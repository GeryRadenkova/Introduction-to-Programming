#include <iostream>

const int smallCircleRadius = 1;
const int mediumCircleRadius = 3;
const int bigCircleRadius = 6;

int main()
{
	float x, y;
	std::cin >> x >> y;

	bool isInBigCircle = (x * x + y * y) < bigCircleRadius * bigCircleRadius;

	//zashto ne moje  bool isInSmallCircleUpperY = x *x + y * y < smallCircleRadius * smallCircleRadius;
	std::cout << (y - mediumCircleRadius);
	bool isInSmallCircleUpperY = x * x + (y - mediumCircleRadius) * (y - mediumCircleRadius) < smallCircleRadius * smallCircleRadius;
	bool isInSmallCircleLowerY = x * x + (y + mediumCircleRadius) * (y + mediumCircleRadius) < smallCircleRadius * smallCircleRadius;

	bool isInMediumCircleUpperY = x * x + (y - mediumCircleRadius) * (y - mediumCircleRadius) < mediumCircleRadius * mediumCircleRadius;
	bool isInMediumCircleLowerY = x * x + (y + mediumCircleRadius) * (y + mediumCircleRadius) < mediumCircleRadius * mediumCircleRadius;

	if (isInBigCircle)
	{
		if (x < 0) //in left quadrant
		{
			if ((!isInMediumCircleLowerY || isInSmallCircleLowerY) && !isInSmallCircleUpperY)
				std::cout << "Good\n";
			else
				std::cout << "Evil\n";
		}
		else //in right quadrant
		{
			if ((!isInMediumCircleUpperY || isInSmallCircleUpperY) && !isInSmallCircleLowerY)
				std::cout << "Evil\n";
			else
				std::cout << "Good\n";
		}
	}
	else
		std::cout << "Neutral\n";

	return 0;
}
