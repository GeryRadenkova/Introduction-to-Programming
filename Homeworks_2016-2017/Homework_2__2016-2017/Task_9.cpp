#include <iostream>

bool func(unsigned int number1, unsigned int number2)
{
	if (number2 > number1)
		return false;

	while (number1 != 0 || number2 != 0)
	{
		if (number1 % 10 != number2 % 10)
		{
			number1 /= 10;
			if (number1 % 10 != number2 % 10)
				return false;
		}

		number1 /= 10;
		number2 /= 10;
	}

	return true;
}

int main()
{
	unsigned int number1, number2;
	std::cin >> number1 >> number2;

	std::cout << func(number1, number2) << std::endl;

	return 0;
}