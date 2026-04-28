#include <iostream>
#include <string>
#include "board.h"
#include "inputValidation.h"
#include <vector>
#include <optional>
#include <algorithm>

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

static Coord getCoordFromUser(Board& board)
{
	const int size{ board.getSize() };
	int x{};
	int y{};

	while (true) {
		y = getValidInput("row", size);
		x = getValidInput("column", size);

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
	const int size{ board.getSize() };

	bool isX{ true };
	bool isTied{ true };
	board.print();

	for (int moves{ 0 }; moves < size * size; ++moves)
	{
		char piece{ isX ? 'X' : 'O' };
		std::cout << "======= Player '" << piece << "' Turn! ======= \n";
		Coord coord{};
		coord = getCoordFromAI(board, piece);

		//if (isX)
		//	coord = getCoordFromAI(board, piece);
		//else
		//	coord = getCoordFromUser(board);
		board.set(coord, piece);
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

	if (!keepPlaying)
		std::cout << "Thank you for playing! \n";

	return keepPlaying;
}

int minimax(Board& board, char currPiece, bool isPiece, int capacity)
{
	if (hasWon(board, currPiece))
		return isPiece ? capacity : -1 * capacity;

	if (capacity == 0)
		return 0;

	int score{};
	int bestScore{ board.m_size * board.m_size };
	if (!isPiece) bestScore *= -1;
	
	const char oppPiece = currPiece == 'X' ? 'O' : 'X';
	for (int i{ 0 }; i < 9; ++i)
	{
		int x{ i % 3 };
		int y{ i / 3 };
		if (!board.isEmpty({ x, y }))
			continue;

		board.m_grid[y][x] = oppPiece;
		score = minimax(board, oppPiece, !isPiece, capacity - 1);
		board.m_grid[y][x] = '-';

		bestScore = isPiece ? std::min(score, bestScore) : std::max(score, bestScore);
	}

	return bestScore;
}

Coord getCoordFromAI(Board& board, char piece)
{
	// 9 positions, calculate coord from it
	// Get score for each of them, pick the highest one

	int score{};
	int bestScore{ -1 * board.m_size * board.m_size }; // Default to worst possible score
	int idx{ 0 };

	int capacity{ 0 };
	for (int i{ 0 }; i < 9; ++i)
	{
		int x{ i % 3 };
		int y{ i / 3 };
		if (board.isEmpty({ x, y }))
			capacity += 1;
	}

	for (int i{ 0 }; i < 9; ++i)
	{
		int x{ i % 3 };
		int y{ i / 3 };
		if (!board.isEmpty({ x, y }))
			continue;

		board.m_grid[y][x] = piece;
		score = minimax(board, piece, true, capacity - 1);
		board.m_grid[y][x] = '-';

		if (score > bestScore)
		{
			bestScore = score;
			idx = i;
		}
	}

	return Coord { idx % 3 , idx / 3 };
}

// How to make AI?
// Check if there's a winning move
// If not, begin looking recursively
//		check if there's a winning move for opponent
//		