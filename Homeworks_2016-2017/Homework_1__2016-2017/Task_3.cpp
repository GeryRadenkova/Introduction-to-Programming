//#include <iostream>
//
//int main()
//{
//	unsigned int number;
//	std::cout << "Enter number: ";
//	std::cin >> number;
//
//	if (number > UINT_MAX)
//	{
//		std::cout << "Number out of range\n";
//		return 0;
//	}
//
//	int prev = 0, curr = 0;
//
//	prev = number % 16;
//	number /= 16;
//
//	while (number != 0)
//	{
//		curr = number % 16;
//		number /= 16;
//
//		if (curr != prev)
//		{
//			std::cout << "No\n";
//			return 0;
//		}
//	}
//
//	std::cout << "Yes\n";
//
//	return 0;
//}