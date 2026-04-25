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

struct Coord {
	int x{};
	int y{};
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

	void set(Coord c, char piece) { m_grid[c.y][c.x] = piece;}
	char get(Coord c) const { return m_grid[c.y][c.x]; }
	bool isEmpty(Coord c) const { return (get(c) == '-'); }

	bool isValid(Coord c) const
	{
		return (c.x >= 0 && c.x < m_size)
			&& (c.y >= 0 && c.y < m_size);
	}

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

};

// TODO: Input validation
//		multiple inputs
//		not ints, eof,
Coord getCoordFromUser()
{
	Coord c{};
	std::cout << "Input x coordinate (0-3): ";
	std::cin >> c.x;

	std::cout << "Input y coordinate (0-3): ";
	std::cin >> c.y;

	return c;
}

int main()
{

	Game game{ 3 };
	
	game.print();

	game.set(Coord { 0, 0 }, 'X');
	game.set({ 1, 1 }, 'O');
	game.set({ 2, 0 }, 'X');
	game.set({ 0, 1 }, 'O');

	game.print();

	return 0;
}