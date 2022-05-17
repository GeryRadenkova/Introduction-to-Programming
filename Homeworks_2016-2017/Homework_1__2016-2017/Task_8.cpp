//#include <iostream>
//
//const int bgn50 = 50;
//const int bgn20 = 20;
//const int bgn10 = 10;
//const int bgn5 = 5;
//const int bgn2 = 2;
//const int bgn1 = 1;
//
//void countNominal(int& number, const int bgn)
//{
//	int count = number / bgn;
//
//	if (count != 0)
//	{
//		std::cout << count << "*" << bgn << " + ";
//		number -= (count * bgn);
//	}
//}
//
//int main()
//{
//	int number;
//	std::cin >> number;
//
//	if (number < 0)
//	{
//		std::cout << "Invalid number.\n";
//		return 0;
//	}
//
//	std::cout << number << " = ";
//
//	countNominal(number, bgn50);
//	countNominal(number, bgn20);
//	countNominal(number, bgn10);
//	countNominal(number, bgn5);
//	countNominal(number, bgn2);
//	countNominal(number, bgn1);
//
//	return 0;
//}