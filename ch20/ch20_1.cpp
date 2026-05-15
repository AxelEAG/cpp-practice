//#include <iostream>
//#include <utility> // for std::swap
//
//int foo()
//{
//	return 5;
//}
//
//int goo()
//{
//	return 6;
//}
//
//void print(int x)
//{
//	std::cout << "print(int)\n";
//}
//
//void print(int x, int y = 10)
//{
//	std::cout << "print(int, int)\n";
//}
//
//bool ascending(int x, int y)
//{
//    return x > y;
//}
//
//bool descending(int x, int y)
//{
//    return x < y;
//}
//
//void selectionSort(int* array, int size, bool (*compare)(int, int)  )
//{
//    if (!array)
//        return;
//
//    // Step through each element of the array
//    for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
//    {
//        // smallestIndex is the index of the smallest element we've encountered so far.
//        int smallestIndex{ startIndex };
//
//        // Look for smallest element remaining in the array (starting at startIndex+1)
//        for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
//        {
//            // If the current element is smaller than our previously found smallest
//            if (compare(array[smallestIndex],array[currentIndex])) // COMPARISON DONE HERE
//            {
//                // This is the new smallest number for this iteration
//                smallestIndex = currentIndex;
//            }
//        }
//
//        // Swap our start element with our smallest element
//        std::swap(array[startIndex], array[smallestIndex]);
//    }
//}
//// This function prints out the values in the array
//void printArray(int* array, int size)
//{
//    if (!array)
//        return;
//
//    for (int index{ 0 }; index < size; ++index)
//    {
//        std::cout << array[index] << ' ';
//    }
//
//    std::cout << '\n';
//}
//
//int main()
//{
//    int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };
//
//    // Sort the array in descending order using the descending() function
//    selectionSort(array, 9, descending);
//    printArray(array, 9);
//
//    // Sort the array in ascending order using the ascending() function
//    selectionSort(array, 9, ascending);
//    printArray(array, 9);
//
//    return 0;
//}
//
////int main()
////{
////	//int (*pfcn)() { &foo };
////	//pfcn = &goo;
////
////	//(*pfcn)();
////	//pfcn();
////
////	//using vnptr = void(*)(int);
////	//vnptr pi{ print };
////	//pi(1);
////
////	//static_cast<void(*)(int)>(print)(1);
////
////
////    return 0;
////
////}