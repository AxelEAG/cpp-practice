//#include <iostream>
//#include <string>
//#include <string_view>
//#include <functional>
//
//
//// using ArithmeticFunction = int(*)(int, int);
//using ArithmeticFunction = std::function<int(int, int)>;
//
//int getInput(std::string_view prompt)
//{
//	while (true)
//	{
//		std::cout << prompt;
//
//		int x{};
//		std::cin >> x;
//		if (!std::cin)
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			std::cout << "Invalid input. Please try again. \n";
//			continue;
//		}
//		if (std::cin.peek() != '\n')
//		{
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			std::cout << "Invalid input. Please try again. \n";
//			continue;
//		}
//
//		return x;
//	}
//}
//
//char getOperation()
//{
//	char operations[]{ '+', '-', '*', '/' };
//	while (true)
//	{
//		std::cout << "Enter a valid operation: ";
//
//		char op{};
//		std::cin >> op;
//		if (!std::cin)
//		{
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			std::cout << "Invalid input. Please try again. \n";
//			continue;
//		}
//		if (std::cin.peek() != '\n')
//		{
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			std::cout << "Invalid input. Please try again. \n";
//			continue;
//		}
//
//		if (std::find(operations, operations + 4, op) == operations + 4)
//		{
//			std::cout << "Invalid operator. Please try again.\n";
//			continue;
//		}
//
//		return op;
//	}
//}
//
//
//int add(int x, int y)
//{
//	return x + y;
//}
//
//int subtract(int x, int y)
//{ 
//	return x - y;
//}
//
//int multiply(int x, int y)
//{
//	return x * y;
//}
//
//int divide(int x, int y)
//{
//	return x / y;
//}
//
//ArithmeticFunction getArithmeticFunction(char op)
//{
//	switch (op)
//	{
//	case '+': return add;
//	case '-': return subtract;
//	case '*': return multiply;
//	case '/': return divide;
//	}
//	return nullptr;
//}
//
//int main()
//{
//
//
//	while (true)
//	{
//		int x{ getInput("Enter a valid integer: ") };
//		int operation{ getOperation() };
//
//		int y{ getInput("Enter a valid integer: ") };
//		if (operation == '/' && y == 0)
//		{
//			std::cout << "Cannot divide by 0! \n";
//			continue;
//		}
//
//		ArithmeticFunction op{ getArithmeticFunction(operation) };
//		if (op) std::cout << "Result: " << op(x, y);
//		break;
//
//	}
//
//	return 0;
//}