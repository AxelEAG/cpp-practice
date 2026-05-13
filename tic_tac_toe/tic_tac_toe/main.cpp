// Terminal tic tac toe
// Players take turns to place their pieces, either 'X' or 'O' on a 3x3 grid.
// Whoever manages to put three in the same column, row or diagonal first wins.

// Don't really need to create many classes but for the sake of practice will.

// Need:
// Players - keep track of who's who
// Game - keeps track of board

// functions: 
//		print board
//		ask next move (will be asked as a (x,y) coord.
//		

#include <iostream>
#include <string>
#include <string_view>
#include <format>
#include <limits>
#include <cstdlib>


struct Coord 
{
	int x{};
	int y{};
};

// TODO: Make compatible with different sizes
// TODO: Initialize grid correctly
class Game
{
private:
	int m_size{ 3 };
	char m_grid[3][3] =
	{
		{ '-', '-', '-' },
		{ '-', '-', '-' },
		{ '-', '-', '-' }
	};

public:
	Game(int size = 3) : m_size{ size } { reset(); }

	void set(Coord coord, char piece) { m_grid[coord.y][coord.x] = piece;}
	char get(Coord coord) const { return m_grid[coord.y][coord.x]; }
	int  getSize() const { return m_size; }

	bool play()
	{
		bool isX{ true };
		bool isTied{ true };
		print();

		for (int moves{ 0 }; moves < m_size * m_size; ++moves)
		{
			char piece{ isX ? 'X' : 'O' };
			std::cout << "======= Player '" << piece << "' Turn! ======= \n";
			set(getCoordFromUser(), piece);
			print();
			isX = !isX;
			if (hasWon(piece))
			{
				std::cout << "Player '" << piece << "' won! \n \n";
				isTied = false;
				break;
			}
		}

		if (isTied) std::cout << "Uh oh, it's a tie! \n \n";

		std::cout << "Would you like to play again (y/n)? ";
		char response{};
		std::cin >> response;
		std::cout << '\n';

		return response == 'y' ? true : false;
	}

	void print() const
	{
		for (int i{ 0 }; i < m_size; ++i)
		{
			for (int j{ 0 }; j < m_size - 1; ++j)
			{
				std::cout << ' ' << m_grid[i][j] << ' ' << '|';
			}
			std::cout << ' ' << m_grid[i][m_size - 1] << ' ' << '\n'; // last one shouldn't have a '|'
			
			if (i != m_size - 1) std::cout << std::string(4*m_size - 1, '-');
			std::cout << '\n';
		}
		

	}

	void reset()
	{
		for (int i{ 0 }; i < m_size; ++i)
		{
			for (int j{ 0 }; j < m_size; ++j)
			{
				m_grid[i][j] = '-';
			}
		}
	}

	// TODO: Improve?
	bool hasWon(char piece) const
	{
		// Check any row wins
		for (int row{ 0 }; row < m_size; ++row)
		{
			bool wonRow{ true };
			for (int col{ 0 }; col < m_size; ++col)
			{
				if (get({ col, row }) != piece)
				{
					wonRow = false;
					break;
				}
			}
			if (wonRow) return true;
		}

		// Check any col wins
		for (int col{ 0 }; col < m_size; ++col)
		{
			bool wonCol{ true };
			for (int row{ 0 }; row < m_size; ++row)
			{
				if (get({ col, row }) != piece)
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
		for (int i{ 0 }; i < m_size; ++i)
		{
			if (get({ i, i }) != piece)
				d1 = false;
			if (get({ m_size - 1 - i, i }) != piece)
				d2 = false;
			if (!d1 && !d2)
				break;
		}
		return (d1 || d2);
	}

	// TODO: Input validation
	// meaningless value, eof
	// additional input
	// extraction fails 
	// extraction overflows
	Coord getCoordFromUser() const
	{
		int x{};
		int y{};

		while (true) {
			int x{ getValidInput("row", m_size) };
			int y{ getValidInput("column", m_size) };

			if (m_grid[y - 1][x - 1] == '-')
				break;

			std::cout << "Please enter a cell that hasn't been played. \n";
		}
		std::cout << '\n';

		return Coord { x - 1, y - 1};
	}



};

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
	// Only proceed if extraction failed
	if (std::cin)
		return false;

	// Halt program if user entered EOF
	if (std::cin.eof())
		std::exit(0);

	std::cin.clear();
	ignoreLine();

	return true;
}

// returns true if had unextracted input and cleans it
bool clearUnextractedInput()
{
	if (std::cin.peek() == '\n')
		return false;

	ignoreLine();
	return true;
}


int getValidInput(std::string_view type, int max, int min=1)
{
	while (true)
	{
		std::cout << std::format("Input valid {} (1-{}): ", type, max);
		int value{};
		std::cin >> value;
		if (clearFailedExtraction() || clearUnextractedInput())
			continue;

		if (value >= min && value <= max)
			return value;
	}

}

int main()
{
	const int size{ 3 };

	Game game{ size };
	std::cout << "Let's play some tic tac toe! \n \n";
	
	while (game.play())
	{
		game.reset();
	};
	return 0;
}