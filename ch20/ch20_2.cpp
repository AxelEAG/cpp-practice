//#include <iostream>
//#include <vector>
//
//int nthFibonacci(int count)
//{
//	if (count == 0)
//		return 0;
//	if (count == 1)
//		return 1;
//
//	return nthFibonacci(count - 1) + nthFibonacci(count - 2);
//}
//
//int memoNthFibonacci(std::size_t count)
//{
//	static std::vector results{ 0, 1 };
//
//	if (count < std::size(results))
//		return results[count];
//
//	results.push_back(memoNthFibonacci(count - 1) + memoNthFibonacci(count - 2));
//	return results[count];
//}
//
//int iterNthFibonacci(std::size_t count)
//{
//	//std::vector<int> results{ 0, 1 };
//	//results.reserve(count);
//
//	//for (std::size_t i{ 2 }; i < count; ++i)
//	//	results.push_back(results[i - 1] + results[i - 2]);
//
//	//return results[count];
//	int pprev{ 0 };
//	int prev{ 1 };
//	int tmp{};
//	for (std::size_t i{ 2 }; i <= count; ++i)
//	{
//		tmp   = pprev;
//		pprev = prev;
//		prev += tmp;
//	}
//	return prev;
//}
//
//int main()
//{
//	for (int i{ 0 }; i < 10; ++i)
//		std::cout << "Fibonacci" << '(' << i << ')' << ": " << iterNthFibonacci(i) << '\n';
//
//	return 0;
//}