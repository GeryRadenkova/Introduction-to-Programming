#include<iostream>

const long long int MAX_SIZE = 4000000000;

int countDigits(int num)
{
	int count = 0;
	while (num != 0)
	{
		count++;
		num /= 10;
	}

	return count;
}

int numberOfOccurences(int a, int b)
{
	int count = 0;
	int numLength = countDigits(a);


	while (b != 0)
	{
		
		if (b % 10 == a % 10)
		{
			int newNum = b % 10;
			int temp = b / 10;
			for (int i = 1; i < numLength; i++)
			{
				int temp2 = temp % 10;
				temp2 *= 10;
				newNum += temp2;
			}

			if (a == newNum)
				count++;
		}

		b /= 10;
	}

	return count;
}

int main()
{
	long long int a, b;
	std::cin >> a >> b;

	if (a > MAX_SIZE || b > MAX_SIZE)
	{
		std::cout << "Invalid numbers.\n";
		return 0;
	}

	std::cout << numberOfOccurences(a, b) << std::endl;

	return 0;
}