#include <iostream>

//4. �������� ��������, ����� �� ������� ����� ������ ���� �������� ������ �� ������ �������� � ������.

int Sum(int* arr, int size) {

	if (size == 0)return 0;

	return ( arr[0] + Sum(arr+1, --size));
}

int main() {

	int arr[] = { 7,3,4,1 };
	std::cout << Sum(arr, 4);

	return 0;
}