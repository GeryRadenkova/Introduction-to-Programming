#include <iostream>

const int DICTIONARY_WORD_SIZE = 40;
const int STRING_SIZE = 80;

void reverse(int beg, int end, char* string, size_t size);
void swap(int i, int j, char* string);
void clean(char** dictionary, int n);
void strcpy1(char* dest, const char* src);

int main() {

	unsigned int n;
	std::cout << "Enter dictionary size> ";
	std::cin >> n;
	char c = std::cin.get(); //to get '/n'

	char** dictionary = new (std::nothrow) char*[n];

	if (!dictionary)
		return -1;

	std::cout << "Enter dictionary words> ";
	char buff[DICTIONARY_WORD_SIZE];
	for (int i = 0; i < n; ++i) {

		if (i == n - 1)  // only to read the last word
			std::cin.getline(buff, DICTIONARY_WORD_SIZE);
		else 
			std::cin.getline(buff, DICTIONARY_WORD_SIZE, ' ');

		size_t len = strlen(buff);
		dictionary[i] = new(std::nothrow) char[len + 1];

		if (!dictionary[i]) 
			clean(dictionary, i);
		
		strcpy1(dictionary[i], buff);
	}

	std::cout << "Enter a string> ";

	char string[STRING_SIZE];
	std::cin.getline(string, STRING_SIZE);

	size_t count = 0;
	int beg = 0;
	int beginning;
	int end;
	size_t size;
	while(string[count] != '\0') {

		++count;
		if ((string[count - 1] == ' ' || string[count - 1] == '\t') && (string[count] != ' ' || string[count] != '\t')) {

			beg = count;
		}
		else if ((string[count - 1] != ' ' || string[count - 1] != '\t') && (string[count] == ' ' || string[count] == '\t') || (string[count] == '\0')) {

			end = count;
			size = end - beg;

			char* temp = new (std::nothrow) char[size + 1];
			beginning = beg;  // do not want to change the value of beg
			for (int i = 0; i < size; ++i) 
				temp[i] = string[beginning++];
			
			temp[size] = '\0';

			for (int i = 0; i < n; ++i) {
				if (!strcmp(temp, dictionary[i])) 
					reverse(beg, end, string, size);
			}
			delete[] temp;
		}
	} 
	std::cout << string;
	clean(dictionary, n);

	return 0;
}

void reverse(int beg, int end, char* string, size_t size) {

	int middle =  size / 2;
	end--;

	for (int i = 0; i < middle; ++i) {
		swap(beg, end, string);
		++beg;
		--end;
	}
}

void swap(int i, int j, char* string) {

	char temp = string[i];
	string[i] = string[j];
	string[j] = temp;
}

void clean(char** dictionary, int n) {

	for (int i = n - 1; i >= 0; --i) 
		delete[] dictionary[i];

	delete[] dictionary;
}

void strcpy1(char* dest, const char* src) {

	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
