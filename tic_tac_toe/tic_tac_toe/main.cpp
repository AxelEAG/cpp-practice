// Terminal tic tac toe
// Players take turns to place their pieces, either 'X' or 'O' on a 3x3 grid.
// Whoever manages to put three in the same column, row or diagonal first wins.

#include <iostream>
#include "board.h"

bool play(Board& board);

int main()
{
	const int size{ 3 };

	Board board{ size };
	std::cout << "Let's play some tic tac toe! \n \n";
	
	while (play(board))
	{
		board.reset();
	};
	return 0;
}