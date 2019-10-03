#include<iostream>

const int STRING_SIZE = 80;
const int U_SHORT_SIZE = 65535;

bool isNumInDictionary(unsigned short num, unsigned short* dictionary, size_t n);

int main() {

	size_t n;
	std::cout << "Enter dictionary size> ";
	std::cin >> n;

	std::cout << "Enter dictionary contents> ";
	unsigned short* dictionary = new (std::nothrow) unsigned short[n];
	for (int i = 0; i < n; ++i) 
		std::cin >> dictionary[i];
	
	char c = std::cin.get(); // to get '\n'
	std::cout << "Enter a string> ";
	char string[STRING_SIZE];
	std::cin.getline(string, STRING_SIZE);

	size_t len = std::strlen(string); //count from '0'
	int num = 0;
	int temp;
	size_t count = 1;
	int sum = 0;

	while (len != 0) {

		--len;
		if ((string[len + 1] < '0' || string[len + 1] > '9') && (string[len] >= '0' && string[len] <= '9')) {

			count = 1;
			num = string[len] - '0';
		}
		else if (string[len + 1] >= '0' && string[len + 1] <= '9' && string[len] >= '0' && string[len] <= '9') {

			count *= 10;
			temp = string[len] - '0';
			temp *= count;
			num += temp;
		}

		if (string[len + 1] >= '0' && string[len + 1] <= '9' && (string[len] < '0' || string[len] > '9') || (len == 0&&string[len]>='0'&&string[len]<='9')) {

			if (num < U_SHORT_SIZE) {
				unsigned short temp = (unsigned short)num;

				if (isNumInDictionary(num, dictionary, n))
					sum += num;
			}
		}
	}

	delete[] dictionary;
	std::cout << sum;

	return 0;
}

bool isNumInDictionary(unsigned short num, unsigned short* dictionary, size_t n) {

	for (int i = 0; i < n; ++i) {
		if (num == dictionary[i]) 
			return true;
	}
	return false;
}