#include <iostream>

unsigned int fact(unsigned int num)
{
	unsigned int result = 1;

	for (int i = 1; i <= num; i++)
		result *= i;

	return result;
}

int main()
{
	unsigned int n;
	std::cout << "Enter n: ";
	std::cin >> n;

	unsigned int fact_n = fact(n);
	unsigned int fact_k;

	std::cout << 1 << " ";

	for (int k = 1; k < n; k++)
	{
		fact_k = fact(k);
		std::cout << fact_n / (fact_k * fact(n - k)) << " ";
	}

	std::cout << 1 << std::endl;

	return 0;
}