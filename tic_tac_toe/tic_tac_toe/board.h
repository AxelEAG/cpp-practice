#ifndef BOARD_H
#define BOARD_H
#include "coord.h"

// TODO: Make compatible with different sizes
// TODO: Initialize grid correctly
class Board
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
	Board(int size = 3) : m_size{ size } { reset(); }

	void set(Coord coord, char piece) { m_grid[coord.y][coord.x] = piece; }
	char get(Coord coord) const { return m_grid[coord.y][coord.x]; }
	bool isEmpty(Coord coord) const { return (m_grid[coord.y][coord.x] == '-'); }
	int  getSize() const { return m_size; }

	void print() const;
	void reset();
}; 

#endif