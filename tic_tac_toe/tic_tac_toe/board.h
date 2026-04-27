#ifndef BOARD_H
#define BOARD_H
#include "coord.h"
#include <vector>

class Board
{
private:
	const int m_size{ 3 };
	std::vector<std::vector<char>> m_grid;

public:
	Board(int size = 3) 
		: m_size{ size }
		, m_grid(m_size, std::vector<char>(m_size, '-'))
	{}

	void set(Coord coord, char piece) { m_grid[coord.y][coord.x] = piece; }
	char get(Coord coord) const { return m_grid[coord.y][coord.x]; }
	bool isEmpty(Coord coord) const { return (m_grid[coord.y][coord.x] == '-'); }
	int  getSize() const { return m_size; }

	void print() const;
	void reset();
	friend Coord getCoordFromAI(Board& board, char piece);
	friend int checkPath(Board& board, char piece);

}; 

#endif