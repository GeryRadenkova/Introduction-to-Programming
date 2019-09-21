#include<iostream>

bool isPalindrom(char* string, int size, int index) {

	if (index + 1 == size || index == size) return true;

	return (string[index] == string[size-1]) && isPalindrom(string, --size, index+1);
}

int main() {

	char arr[] = "baggab";
	std::cout << isPalindrom(arr, 6, 0);

	return 0;
}