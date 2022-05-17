#include <iostream>

bool isPrime(int number) 
{
	if (number < 2) 
		return false;	

	int sq = sqrt(number);

	for (int i = 2; i <= sq; i++)
		if (number % i == 0)
			return false;

	return true;
}

int main()
{
	int n;
	std::cin >> n;

	if (n < 0 || n > 100000)
	{
		std::cout << "Invalid number.\n";
		return 0;
	}

	int count = 0;
	int p = 2; //start from the first prime number

	while (count != n)
	{
		if (isPrime(p))
		{
			int q = p + 2;
			if (isPrime(q))
			{
				count++;
				std::cout << p << ' ' << q << std::endl;
			}
		}

		p++;
	}

	return 0;
}