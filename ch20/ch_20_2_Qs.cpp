#include <cassert>
#include <iostream>
#include <limits>
// Q1

//int factorial(int n)
//{
//	if (n == 0)
//		return 1;
//	
//	return n*factorial(n - 1);
//}
//
//int main()
//{
//
//	int fact{ 1 };
//	for (int i{ 1 }; i < 8; ++i)
//	{
//		fact *= i;
//		int res = factorial(i);
//		std::cout << "factorial" << '(' << i << ')' << ": " << res << '\n';
//		assert(factorial(i) == fact);
//	}
//	return 0;
//}

// Q2

//int digitSum(int num)
//{
//	if (num < 10)
//		return num;
//
//	return ((num % 10) + digitSum(num / 10));
//}
//
//int main()
//{
//	std::cout << "digitSum" << '(' << 93427 << ')' << ": " << digitSum(93427) << '\n';
//
//	return 0;
//}


void printBinaryHelper(unsigned int num)
{
	if (num == 0)
		return;

	printBinaryHelper(num / 2);
	std::cout << (num % 2);
}

void printBinary(int num)
{
	printBinaryHelper(static_cast<unsigned int>(num));
}

// Q3
int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	printBinary(x);

	return 0;
}