//#include <iostream>
//
//const int MAX = 16;
//
//int main()
//{
//	int num1, num2;
//	char op;
//
//	std::cin >> num1;
//	std::cin >> op;
//	std::cin >> num2;
//
//	//ne mi se poluchi proverkata...
//	//if (op != '+' || op != '-' || op != '*' || op != '/' || op != '%')
//	//{
//	//	std::cout << "Invalid operation!\n";
//	//	return 0;
//	//}
//
//	while (num1 > MAX)
//		num1 -= MAX;
//	
//	while (num2 > MAX)
//		num2 -= MAX;
//
//	switch (op)
//	{
//	case '+':
//		std::cout << (((num1 + num2) > MAX) ? ((num1 + num2) - MAX) : (num1 + num2)) << std::endl; break;
//	case '-':
//		std::cout << (((num1 - num2) > MAX) ? ((num1 - num2) - MAX) : (num1 - num2)) << std::endl; break;
//	case '*':
//		std::cout << (((num1 * num2) > MAX) ? ((num1 * num2) - MAX) : (num1 * num2)) << std::endl; break;
//	case '/':
//		if (num2 == 0)
//		{ 
//			std::cout << "Division by zero!\n";
//			break;
//		}
//		std::cout << (((num1 / num2) > MAX) ? ((num1 / num2) - MAX) : (num1 / num2)) << std::endl; break;
//
//	case '%':
//		if (num2 == 0)
//		{
//			std::cout << "Division by zero!\n";
//			break;
//		}
//		std::cout << (((num1 % num2) > MAX) ? ((num1 % num2) - MAX) : (num1 % num2)) << std::endl; break;
//	}
//
//
//	return 0;
//}