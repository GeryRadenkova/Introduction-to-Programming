#include<iostream>

void selectionSort(int* arr, int len);
void swap(int* arr, int ind1, int ind2);

int main() {

	int N;
	std::cout << "Enter N: ";
	std::cin >> N;

	int* num = new (std::nothrow) int[N];
	if (!num) {

		std::cout << "Fail to allocate memory.";
		return 1;
	}

	std::cout << "Enter numbers: ";
	for (int i = 0; i < N; ++i) 
		std::cin >> num[i];

	selectionSort(num, N);
	
	int count_numbers = 1;
	for (int i = 1; i < N ; ++i) {

		if (num[i] != num[i - 1])
			++count_numbers;
	}

	int* numbers = new(std::nothrow) int[count_numbers];
	if (!numbers) {

		std::cout << "Fail to allocate memory.";
		return 1;
	}

	int j = 0;
	for (int i = 0; i < N - 1; ++i) {

		if (num[i] != num[i + 1])
			numbers[j++] = num[i];
	}
	numbers[j] = num[N - 1];
	delete[] num;

	for (int i = 0; i < count_numbers; ++i)
		std::cout << numbers[i] << " ";
	
	delete[] numbers;

	return 0;
}

void selectionSort(int* arr, int len) {

	for (int i = 0; i < len; ++i) {

		int min = arr[i];
		int minIndex = i;
		for (int j = i + 1; j < len; ++j) {

			if (arr[j] > min) {
				min = arr[j];
				minIndex = j;
			}
		}
		swap(arr, i, minIndex);
	}
}

void swap(int* arr, int ind1, int ind2){

	int temp = arr[ind1];
	arr[ind1] = arr[ind2];
	arr[ind2] = temp;
}