#ifndef FLOATING_POINT_NUMBER_H
#define FLOATING_POINT_NUMBER_H
#include <iostream>
#include <string>

const int MAX_SIZE = 24;

class FloatingPointNumber
{
private:
	char fpNumber[3];  //floating point number

	//std::string decimalToBinary(double num, int precision);

	std::string decimalToBinary(int num);
	std::string fractionalToBinary(double num, int precision);
	int normalizingMantissa(std::string& binary); // retun the value of exponent
	void makeExponentsTheSame(int exp1, int exp2, FloatingPointNumber& num1, FloatingPointNumber& num2);

public:
	FloatingPointNumber(double num);
	FloatingPointNumber operator+(FloatingPointNumber& rhs);
};

#endif //FLOATING_POINT_NUMBER_H