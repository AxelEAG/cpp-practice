#include <iostream>
#include "board.h"
#include <array>
#include <string_view>
#include <format>
#include <iomanip>
#include <ios>

int getAIMove(Board& board, char piece);

struct Test
{
	std::string_view name{};
	Board board{};
	char piece{};
	int expectedResult{};
};

std::array<Test, 4> winningTests{ {
	Test {
		"Completes top row",
		{{  'X', 'X', '-',
			'O', 'O', '-',
			'-', 'O', '-' 
		}},
		'X',
		2
	},

	Test {
		"Completes left column",
		{{  'O', '-', '-',
			'O', 'X', '-',
			'-', 'X', '-' }},
		'O',
		6
	},

	Test {
		"Completes main diagonal",
		{{  'X', '-', '-',
			'-', 'X', '-',
			'-', '-', '-' 
		}},
		'X',
		8
	},

	Test {
		"Completes bottom row",
		{{  '-', '-', '-',
			'X', '-', '-',
			'O', 'O', '-' 
		}},
		'O',
		8
	},
} };

std::array<Test, 4> blockingTests{ {
	Test {
		"Blocks opponent top row",
		{{  'X', 'X', '-',
			'-', '-', '-',
			'-', 'O', '-'
		}},
		'O',
		2
	},

	Test {
		"Blocks opponent left column",
		{{  'X', '-', '-',
			'X', 'O', '-',
			'-', '-', '-'
		}},
		'O',
		6
	},

	Test {
		"Blocks opponent diagonal",
		{{  'X', '-', '-',
			'O', 'X', '-',
			'-', '-', '-'
		}},
		'O',
		8
	},

	Test {
		"Blocks opponent bottom row",
		{{ '-', '-', '-',
			'X', '-', '-',
			'O', 'O', '-' }},
		'X',
		8
	},
} };


void printResult(std::string_view name, bool result)
{
	std::cout << std::left << std::setw(10) << (result ? "[PASSED]" : "[FAILED]") << name << '\n';
}

template <std::size_t N>
void runTests(std::array<Test, N>& tests, std::string_view group)
{
	std::cout << "===== " << group << " =====" << '\n';

	int passed{ 0 };
	int failed{ 0 };
	for ( Test& test : tests)
	{
		int move{ getAIMove(test.board, test.piece) };
		if (move == test.expectedResult)
		{
			printResult(test.name, true);
			++passed;
		}
		else
		{
			printResult(test.name, false);
			std::cout << "Board: \n";
			test.board.print();
			std::cout << "Expected move: " << test.expectedResult << '\n';
			std::cout << "Actual move:   " << move << '\n';
			++failed;
		}
	}
	std::cout << '\n';
	std::cout << "Expected: " << tests.size() << '\n';
	std::cout << "Actual:   " << passed << '\n' << '\n';

}

void testAI()
{
	runTests(winningTests, "Winning Moves");
	runTests(blockingTests, "Blocking Moves");

}
