#include <iostream>

int main()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;

	int sum = 0;
	int value = 1;

	for (int i = 0; i < n * n; i++)
	{
		std::cout << sum << ';';
		sum += value;
		value *= 2;
	}
	
	std::cout << sum << std::endl;

	return 0;
}