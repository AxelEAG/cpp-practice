#ifndef BOARD_H
#define BOARD_H
#include <vector>

class Board
{
private:
	const int m_size{ 3 };
	int m_capacity{m_size * m_size};
	std::vector<char> m_grid;

public:
	Board(int size = 3) 
		: m_size{ size }
		, m_capacity{ size * size }
		, m_grid(m_capacity, '-')
	{}

	// For testing only, sets up predefined board
	Board(std::vector<char> grid, int size = 3)
		: m_size{ size }
		, m_capacity{ size * size }
		, m_grid{ grid }
	{
		for (int i{ 0 }; i < m_size * m_size; ++i)
			if (!isEmpty(i)) --m_capacity;
	}

	void set(int idx, char piece) 
	{
		m_grid[idx] = piece; 
		--m_capacity;
	}
	void reset(int idx)
	{
		m_grid[idx] = '-';
		++m_capacity;
	}

	char get(int idx) const { return m_grid[idx]; }
	bool isEmpty(int idx) const { return (m_grid[idx] == '-'); }
	int  getSize() const { return m_size; }
	int	 getCapacity() const { return m_capacity; }

	void print() const;
	void reset();

}; 

#endif