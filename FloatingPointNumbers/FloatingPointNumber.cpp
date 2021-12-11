#include "FloatingPointNumber.h"

std::string FloatingPointNumber::decimalToBinary(int num)
{
    std::string binary = "";

    while (num)
    {
        int remainder = num % 2;
        binary.push_back(remainder + '0');
        num /= 2;
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

std::string FloatingPointNumber::fractionalToBinary(double num, int precision)
{
    std::string binary = "";

    int integral = num;
    double fractional = num - integral;

    binary.push_back('.');

    while (precision--)
    {
        fractional *= 2;
        int fract_bit = fractional;

        if (fract_bit == 1)
        {
            fractional -= fract_bit;
            binary.push_back(1 + '0');
        }
        else
            binary.push_back(0 + '0');
    }

    return binary;
}

int FloatingPointNumber::normalizingMantissa(std::string& binary)
{
    int exponent = 0;
    
    if (binary[0] == '.')  //point was moved right (negative exponent)
    {
        while (binary[0] != '1')
        {
            binary.erase(binary.begin());
            exponent--;
        }

        binary.insert( 1, ".");
    }
    else if (binary[0] == '1' && binary[1] == '.')  //point is in place
    {
        return exponent;
    }
    else  //point was moved left (positive exponent)
    {
        int ind = 0;
        while (binary[ind] != '.')
        {
            ind++;
            exponent++;
        }

        binary.erase(binary.begin() + ind);
        binary.insert(1, ".");
        exponent--;
    }

    return exponent;
}

void FloatingPointNumber::makeExponentsTheSame(int bigExp, int smallExp, FloatingPointNumber& num1, FloatingPointNumber& num2)
{
    for (int i = smallExp; i < bigExp; i++)
    {
        num1
    }
}

FloatingPointNumber::FloatingPointNumber(double num)
{
    char sign = '0';
    if (num < 0)
    {
        sign = '1';
        num *= -1;
    }

    std::string binaryStr = decimalToBinary(num);

    int precision = 17 - binaryStr.length();
    binaryStr.append(fractionalToBinary(num, precision));

    int exp = normalizingMantissa(binaryStr);
    std::string exponent = decimalToBinary(exp + 31); //(the exponent value is added to a bias of 31)

    fpNumber[0] = sign;

    int ind = 1;
    for (int i = 0; i < exponent.length(); i++)
        fpNumber[ind++] = exponent.at(i);
    
    binaryStr.erase(binaryStr.begin()); // remove implicit 1
    binaryStr.erase(binaryStr.begin()); //remove '.'
    for (int i = 0; i < binaryStr.length(); i++)
        fpNumber[ind++] = binaryStr.at(i);
    
    // fill in up to 17 mantissa values after the loss of the implicit 1
    while (ind < MAX_SIZE)
        fpNumber[ind++] = '0';
    

    for (int i = 0; i < MAX_SIZE; i++)
    {
        std::cout << fpNumber[i] << ' ';
    }
}

FloatingPointNumber FloatingPointNumber::operator+(FloatingPointNumber& rhs)
{
    std::string exponent1, exponent2;
    for (int i = 1; i < 7; i++)
    {
        exponent1 += this->fpNumber[i];
        exponent2 += rhs.fpNumber[i];
    }

    int exp1 = stoi(exponent1, 0, 2);
    int exp2 = stoi(exponent2, 0, 2);

    if (exp1 > exp2)
    {
            
    }
}
