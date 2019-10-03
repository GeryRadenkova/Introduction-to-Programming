#include<iostream>

const int STRING_SIZE = 80;
const int U_SHORT_SIZE = 65535;

bool isNumInDictionary(unsigned short num, unsigned short* dictionary, int n) {

	for (int i = 0; i < n; ++i) {

		if (num == dictionary[i])
			return true;
	}
	return false;
}

int sum(const char* string, unsigned short* dictionary, int n) {

	int len = strlen(string);
	int res = 0;
	int sum = 0;
	for (int i = 0; i < len; i++) {

		while (string[i] >= '0' && string[i] <= '9') {

			res *= 10;
			res += string[i] - '0';
			i++;
		}
		if (!(string[i] >= '0' && string[i] <= '9') && string[i - 1] >= '0' && string[i - 1] <= '9') {

			if (res < U_SHORT_SIZE) {

				if (isNumInDictionary(res, dictionary, n)) {
					sum += res;
					res = 0;
				}
				else 
					res = 0;
			}
		}
	}
	return sum;
}

int main() {

	int n;
	std::cout << "Enter dictionary size> ";
	std::cin >> n;

	unsigned short* dictionary = new (std::nothrow) unsigned short[n];
	std::cout << "Enter dictionary contents> ";
	for (int i = 0; i < n; i++) 
		std::cin >> dictionary[i];

	char c = std::cin.get(); // to get '\n'
	char string[STRING_SIZE];
	std::cout << "Enter string> ";
	std::cin.getline(string, STRING_SIZE);

	std::cout << sum(string, dictionary, n);

	delete[] dictionary;

	return 0;
}