#include<iostream>

const int STRING_SIZE = 80;

size_t DigitPrefix(const char* str);
unsigned int ToInt(const char* str, size_t len);
void strcpy1(char* dest, const char* src);

int main() {
	
	char string[STRING_SIZE];
	std::cout << "Enter a string> ";
	std::cin.getline(string, STRING_SIZE);
	int string_len = strlen(string);

	unsigned int numbers[STRING_SIZE];
	size_t count_numbers = 0;
	int sum = 0;
	int count = 0;
	int beg = 0;

	while (string[count] != '\0') {
		
		if (string[count] >= '0' && string[count] <= '9') {

			beg = count;
			int size = string_len - count;
			char* temp = new (std::nothrow) char[size + 1];
			if (!temp) {
				std::cout << "Fail to allocate memory.";
				return 1;
			}

			for (int i = 0; i < size; ++i)
				temp[i] = string[beg++];
			temp[size] = '\0';

			int len = DigitPrefix(temp);
			if (len > 10) {  //check if the number can be stored in unsigned int
				count += len;
				delete[] temp;
				continue;
			}
				
			char* str = new(std::nothrow) char[len];
			if (!str) {
				std::cout << "Fail to allocate memory.";
				return 1;
			}

			for (int i = 0; i < len; i++)
				str[i] = temp[i];
			str[len] = '\0';

			if (len == 10) {

				char uint[] = "4294967295";
				bool isNumInUint = true;
				for (int i = 0; i < 10; i++) {

					if (str[i] > uint[i]) {
						isNumInUint = false;
						break;
					}
					else if (str[i] < uint[i])
						break;
				}
				if(!isNumInUint) {

					count += len;
					delete[] temp, str;
					continue;
				}
			}
			
			numbers[count_numbers] = ToInt(str, len);
			sum += numbers[count_numbers];
			++count_numbers;
			
			count += len;

			delete[] temp,str;
			continue;
		}
		++count;
	}

	std::cout << count_numbers << std::endl;

	for (int i = 0; i< count_numbers; i++)
		std::cout << numbers[i] << " ";
	
	std::cout << std::endl << sum;

	return 0;
}

size_t DigitPrefix(const char* str) {

	if (*str < '0' || *str > '9') return 0;
	
	return 1 + DigitPrefix(str + 1);
}

unsigned int ToInt(const char* str, size_t len) {

	static int count = 1;
	static int i = 0;
	if (len == 0) {

		count = 1;
		i = 0;
		return 0;
	}
	--len;
	
	if (i > 0) count *= 10;
	++i;

	return (str[len] - '0')* count + ToInt(str, len);
}

void strcpy1(char* dest, const char* src) {

	int i = 0;
	while (src[i] != '\0') {

		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}