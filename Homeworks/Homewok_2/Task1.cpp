#include <iostream>
#include <iomanip>

int main()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	for (int i = 1; i < n - 1; i++)
	{
		std::cout << 1; 
		for (int j = 1; j < n - 1; j++)
		{
			if (i == j || i + j == n - 1)
			{
				std::cout << ' ' << j + 1;  //+1
			}
			else
			{
				if (j + 1 >= 10) //when the number is two-digit number
				{
					std::cout << ' ';
				}
				std::cout << "  ";
			}
		}
		std::cout << ' ' << n;
		std::cout << std::endl;
	}

	for (int i = 1; i <= n; i++)
	{
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	return 0;
}