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

struct Coord 
{
	int x{-1};
	int y{-1};
};

struct Move
{
	Coord coord{};
	char piece{ '-' };
};

// TODO: Make compatible with different sizes
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

	void set(Move& m) { m_grid[m.coord.y][m.coord.x] = m.piece;}
	char get(Coord coord) const { return m_grid[coord.y][coord.x]; }
	int  getSize() const { return m_size; }
	 
	void print() const
	{
		for (int i{ 0 }; i < m_size; ++i)
		{
			for (int j{ 0 }; j < m_size - 1; ++j)
			{
				std::cout << m_grid[i][j] << " | ";
			}
			std::cout << m_grid[i][m_size - 1] << '\n'; // last one shouldn't have a '|'
			
			if (i != m_size -1) std::cout << std::string(4*m_size - 2, '-');
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
	//		multiple inputs
	//		not ints, eof,
	Coord getCoordFromUser() const
	{
		Coord c{};
		while (true) {
			while (c.y < 0 || c.y >= m_size)
			{
				std::cout << "Input valid row (0-" << m_size - 1 << "): ";
				std::cin >> c.y;
			}

			while (c.x < 0 || c.x >= m_size)
			{
				std::cout << "Input valid column (0-" << m_size - 1 << "): ";
				std::cin >> c.x;
			}

			if (get(c) == '-')
				break;

			std::cout << "Please enter a cell that hasn't been played. \n";
		}
		std::cout << '\n';

		return c;
	}

};

int main()
{
	const int size{ 3 };

	Game game{ size };
	bool isX{ true };
	std::cout << " Let's play some tic tac toe! \n \n";
	
	game.print();

	for (int moves{ 0 }; moves < 9; ++moves)
	{
		char piece{ isX ? 'X' : 'O' };
		std::cout << "======= Player '" << piece << "' Turn! ======= \n";
		Move move{game.getCoordFromUser(), piece };
		game.set(move);
		game.print();
		isX = !isX;
	}

	return 0;
}