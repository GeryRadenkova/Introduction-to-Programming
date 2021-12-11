#include <iostream>
#include <string>
#include <vector>
#include "FloatingPointNumber.h"

std::string toBinary(int n, int len)
{
    std::string binary;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary += (n & i) ? "1" : "0";
    }

    return binary;
}

int main()
{
    //bool number = 0;
    ///*for (int i = 0; i < 3; i++)
    //    number[i] = 0;*/

    //int n = 11;
    //int len = 8;

    //std::cout << "The binary representation of " << n << " is " << toBinary(n, len) << std::endl;

    //float num = -3.25;
    //std::to_string(num);
    //std::cout << num << std::endl;

    //std::string p = "3";
    //int new_num = std::stoi(p, nullptr, 10);

	/*int value = 24;
	printf("%0X\n", value);*/

   /* std::string str("This is an example sentence.");
    str.erase(str.begin() + 9);
    std::cout << str << '\n';*/

    FloatingPointNumber n(5);
    std::string test = "Hello";
    test.substr(0, 5);
    test.insert(0, "g");

    std::string t = "101";
    int number = stoi(t, 0, 2);
    std::cout << number;
    std::vector<std::vector<FloatingPointNumber>> list;

    //unsigned long long int t = 11111111111111111;

    int start, end;
    std::cout << "Enter time interval start - end: ";
    std::cin >> start >> end;

    int N;
    std::cin >> N;

    std::string time;
    std::getline(std::cin, time, ' ');

	return 0;
}
