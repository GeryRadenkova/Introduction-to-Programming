#include<iostream>

//Напишете функция, която чрез рекурсия проверява дали масив от цели числа е сортиран

bool isSorted(int* arr, int size) {

	if (size == 1) return true;

	return (arr[size - 1] >= arr[size - 2]) && isSorted(arr, size - 1);
}

int main() {

	int arr[] = { 1,2,3,4,5 };
	std::cout << isSorted(arr, 5);

	return 0;
}
