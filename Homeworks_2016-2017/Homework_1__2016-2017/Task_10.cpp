#include <iostream>

int main()
{
	double a1, b1, c1;
	double a2, b2, c2;

	std::cin >> a1 >> b1 >> c1;
	std::cin >> a2 >> b2 >> c2;

	double det = (a1 * b2) - (b1 * a2);

	if (det != 0)
	{
		double x = ((c1 * b2) - (b1 * c2)) / det;
		double y = ((a1 * c2) - (c1 * a2)) / det;
		std::cout << x << ' ' << y << std::endl;
	}
	else
	{
		if ((c1 - b1) * a2 == (c2 - b2) * a1)
			std::cout << "Many solutions\n";
		else
			std::cout << "No solutions\n";
	}


	return 0;
}
