#include<iostream>

//3.�������� ��������, ����� �� ������� ����� � ����� ������ ���� �������� ���� ������� �� ������� � ������ .

bool isIn(int arr[], int num, int size) {

	if (arr[0] == num) return true;
	if (size == 0) return false;

	return isIn(arr + 1, num, --size);
}

int main() {

	int arr[] = { 7,4,5,9 };
	std::cout << isIn(arr, 3, 4);

	return 0;
}