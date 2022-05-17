//#include <iostream>
//
//int min(int first, int second)
//{
//	return (first > second) ? second : first;
//}
//
//int max(int first, int second)
//{
//	return (first > second) ? first : second;
//}
//
//double area(int lowerLeftX1, int lowerLeftY1, int h1, int w1, int lowerLeftX2, int lowerLeftY2, int h2, int w2)
//{
//	int topRightX1 = lowerLeftX1 + w1;
//	int topRightY1 = lowerLeftY1 + h1;
//
//	int topRightX2 = lowerLeftX2 + w2;
//	int topRightY2 = lowerLeftY2 + h2;
//
//	int xDistance = min(topRightX1, topRightX2) - max(lowerLeftX1, lowerLeftX2);
//	int yDistance = min(topRightY1, topRightY2) - max(lowerLeftY1, lowerLeftY2);
//
//	if (xDistance < 0 || yDistance < 0)
//		return 0;
//
//	return xDistance * yDistance;
//}
//
//int main()
//{
//	int lowerLeftX1, lowerLeftY1, h1, w1;
//	int lowerLeftX2, lowerLeftY2, h2, w2;
//
//	std::cin >> lowerLeftX1 >> lowerLeftY1 >> h1 >> w1; //first rectangle
//
//	std::cin >> lowerLeftX2 >> lowerLeftY2 >> h2 >> w2; //second rectangle
//
//	std::cout << "Area: " << area(lowerLeftX1, lowerLeftY1, h1, w1, lowerLeftX2, lowerLeftY2, h2, w2) << std::endl;
//
//	return 0;
//}