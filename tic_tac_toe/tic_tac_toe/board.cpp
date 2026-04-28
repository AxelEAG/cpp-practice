#include <iostream>
#include <string>
#include "board.h"
#include "inputValidation.h"
#include <vector>
#include <algorithm>

void Board::print() const
{
	for (int i{ 0 }; i < m_size; ++i)
	{
		for (int j{ 0 }; j < m_size - 1; ++j)
		{
			std::cout << ' ' << m_grid[3*i + j]<< ' ' << '|';
		}
		std::cout << ' ' << m_grid[3*i + (m_size - 1)] << ' ' << '\n'; // last one shouldn't have a '|'

		if (i != m_size - 1) std::cout << std::string(4 * m_size - 1, '-'); // also don't close last line
		std::cout << '\n';
	}
}

void Board::reset()
{
	m_capacity = m_size * m_size;

	for (int i{ 0 }; i < m_capacity; ++i)
		m_grid[i] = '-';
}

static int getUserMove(Board& board)
{
	const int size{ board.getSize() };
	int x{};
	int y{};

	while (true) {
		y = getValidInput("row", size) - 1;
		x = getValidInput("column", size) - 1;

		if (board.isEmpty(3*y + x))
			break;

		std::cout << "Please enter a cell that hasn't been played. \n";
	}
	std::cout << '\n';

	return 3*y + x;
}

static bool moveWins(Board& board, int move)
{
	char piece{ board.get(move) };
	const int size{ board.getSize() };
	const int row{ move / size };
	const int col{ move % size };
	const bool inD1{ row == col };
	const bool inD2{ row == ((board.getSize() - 1) - col) };

	bool wonRow{ true };
	bool wonCol{ true };
	bool wonD1{ inD1 };
	bool wonD2{ inD2 };

	for (int i{ 0 }; i < size; ++i)
	{
		if (board.get(3 * row + i) != piece)			wonRow = false;
		if (board.get(3 * i + col) != piece)			wonCol = false;
		if (inD1 && board.get(3 * i + i) != piece)				wonD1 = false;
		if (inD2 && board.get(3 * i + (size - 1) - i) != piece)	wonD2 = false;
	}

	return wonRow || wonCol || wonD1 || wonD2;
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
		int idx{};
		idx = getAIMove(board, piece);
		// idx = getUserMove(board);
		//if (isX)
		//	coord = getAIMove(board, piece);
		//else
		//	coord = getUserMove(board);
		board.set(idx, piece);
		board.print();
		isX = !isX;
		if (moveWins(board, idx))
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

static int minimax(Board& board, int move, char currPiece, bool isPiece)
{
	if (moveWins(board, move))
		return isPiece ? board.getCapacity() : -1 * board.getCapacity();

	if (board.getCapacity() == 0)
		return 0;

	int score{};
	int bestScore{ board.getCapacity() };
	if (!isPiece) bestScore *= -1;
	
	const char oppPiece = currPiece == 'X' ? 'O' : 'X';
	for (int i{ 0 }; i < 9; ++i)
	{
		if (!board.isEmpty(i))
			continue;

		board.set(i, oppPiece);
		score = minimax(board, i, oppPiece, !isPiece);
		board.reset(i);

		bestScore = isPiece ? std::min(score, bestScore) : std::max(score, bestScore);
	}

	return bestScore;
}

int getAIMove(Board& board, char piece)
{
	// 9 positions, calculate coord from it
	// Get score for each of them, pick the highest one

	int score{};
	int bestScore{ -1 * board.getCapacity()}; // Default to worst possible score
	int idx{ 0 };

	for (int i{ 0 }; i < board.getSize() * board.getSize(); ++i)
	{
		if (!board.isEmpty(i))
			continue;

		board.set(i, piece);
		score = minimax(board, i, piece, true);
		board.reset(i);

		if (score > bestScore)
		{
			bestScore = score;
			idx = i;
		}
	}

	return idx;
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
			if (board.get(3 * row + col) != piece)
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
			if (board.get(3 * row + col) != piece)
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
	for (int col{ 0 }; col < size; ++col)
	{
		bool wonCol{ true };
		for (int row{ 0 }; row < size; ++row)
		{
			if (board.get(3 * row + col) != piece)				d1 = false;
			if (board.get(3 * row + (size - 1) - col) != piece) d2 = false;
			if (!d1 && !d2) break;
		}
	}

	return (d1 || d2);
}
