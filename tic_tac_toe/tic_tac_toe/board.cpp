#include <iostream>
#include <string>
#include "board.h"
#include "inputValidation.h"

void Board::print() const
{
	for (int i{ 0 }; i < m_size; ++i)
	{
		for (int j{ 0 }; j < m_size - 1; ++j)
		{
			std::cout << ' ' << m_grid[i][j] << ' ' << '|';
		}
		std::cout << ' ' << m_grid[i][m_size - 1] << ' ' << '\n'; // last one shouldn't have a '|'

		if (i != m_size - 1) std::cout << std::string(4 * m_size - 1, '-'); // also don't close last line
		std::cout << '\n';
	}
}

void Board::reset()
{
	for (int i{ 0 }; i < m_size; ++i)
	{
		for (int j{ 0 }; j < m_size; ++j)
		{
			m_grid[i][j] = '-';
		}
	}
}

static Coord getCoordFromUser(Board& board, int size)
{
	int x{};
	int y{};

	while (true) {
		x = getValidInput("row", size);
		y = getValidInput("column", size);

		if (board.isEmpty({ x - 1, y - 1 }))
			break;

		std::cout << "Please enter a cell that hasn't been played. \n";
	}
	std::cout << '\n';

	return Coord{ x - 1, y - 1 };
}

// TODO: Improve?
static bool hasWon(Board& board, char piece)
{
	const int size{ board.getSize() };

	// Check any row wins
	for (int row{ 0 }; row < size; ++row)
	{
		bool wonRow{ true };
		for (int col{ 0 }; col < size; ++col)
		{
			if (board.get({ col, row }) != piece)
			{
				wonRow = false;
				break;
			}
		}
		if (wonRow) return true;
	}

	// Check any col wins
	for (int col{ 0 }; col < size; ++col)
	{
		bool wonCol{ true };
		for (int row{ 0 }; row < size; ++row)
		{
			if (board.get({ col, row }) != piece)
			{
				wonCol = false;
				break;
			}
		}
		if (wonCol) return true;
	}

	// Check any diagonal wins
	bool d1{ true };
	bool d2{ true };
	for (int i{ 0 }; i < size; ++i)
	{
		if (board.get({ i, i }) != piece)
			d1 = false;
		if (board.get({ size - 1 - i, i }) != piece)
			d2 = false;
		if (!d1 && !d2)
			break;
	}
	return (d1 || d2);
}

bool play(Board& board)
{
	bool isX{ true };
	bool isTied{ true };
	int size{ board.getSize() };
	board.print();

	for (int moves{ 0 }; moves < size * size; ++moves)
	{
		char piece{ isX ? 'X' : 'O' };
		std::cout << "======= Player '" << piece << "' Turn! ======= \n";
		board.set(getCoordFromUser(board, size), piece);
		board.print();
		isX = !isX;
		if (hasWon(board, piece))
		{
			std::cout << "Player '" << piece << "' won! \n \n";
			isTied = false;
			break;
		}
	}

	if (isTied) std::cout << "Uh oh, it's a tie! \n \n";

	char keepPlaying{ getValidAnswer("Would you like to play again (y/n)? ") == 'y' };

	return keepPlaying;
}
