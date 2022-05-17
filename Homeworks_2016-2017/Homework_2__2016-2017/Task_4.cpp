#include <iostream>

bool setOfNumbers(int num1, int num2) //num1 is longer then num2
{
	bool isIn = false;
	int shorterNumber = num2;

	while (num1 != 0)
	{
		int currentDigit = num1 % 10;
		while (shorterNumber != 0)
		{
			if (currentDigit == shorterNumber % 10)
				isIn = true;

			shorterNumber /= 10;
		}

		if (isIn)
		{
			shorterNumber = num2;
			isIn = false;
		}
		else
			return isIn;

		num1 /= 10;
	}

	return true;
}

int main()
{
	int num1, num2;
	std::cin >> num1 >> num2;

	if (num1 < 0)
		num1 *= -1; //num1 = std::abs(num1);

	if (num2 < 0)
		num2 *= -1; //num2 = std::abs(num2);

	if (num1 > num2)
		std::cout << ((setOfNumbers(num1, num2)) ? "Yes\n" : "No\n");
	else
		std::cout << ((setOfNumbers(num2, num1)) ? "Yes\n" : "No\n");

	return 0;
}