#include <iostream>

bool isValidNumber(unsigned int num, unsigned int k)
{
	while (num != 0)
	{
		if (num % 10 >= k)
			return false;
		else
			num /= 10;
	}

	return true;
}

unsigned int reverseNumber(unsigned int num)
{
	unsigned int result = 0;

	while (num != 0)
	{
		result += num % 10;
		result *= 10;
		num /= 10;
	}
	result /= 10;

	return result;
}

unsigned int sum(unsigned int n, unsigned int m, unsigned int k)
{
	if (k == 10)
		return n + m;

	unsigned int result = 0;
	int r = 0;

	while (n != 0 || m != 0)
	{
		result *= 10;
		result += (n % 10 + m % 10 + r) % k;
		r = (n % 10 + m % 10 + r) / k;

		n /= 10;
		m /= 10;
	}

	if (r != 0)
	{
		result *= 10;
		result += r;
	}

	return result;
}

int main()
{
	unsigned int n, m, k;
	std::cin >> n >> m >> k;

	if (k < 2 || k > 10 || m < 0 || m > 500000 || n < 0 || n > 500000)
	{
		std::cout << "Invalid values for n, m, k.\n";
		return -1;
	}

	if (isValidNumber(n, k) && isValidNumber(m, k))
		std::cout << reverseNumber(sum(n, m, k)) << std::endl;
	else
		std::cout << "Bad input data!" << std::endl;

	return 0;
}