#include <iostream>

const int USED = 9999;

void swap(int arr[], int ind1, int ind2) 
{
	int temp = arr[ind1];
	arr[ind1] = arr[ind2];
	arr[ind2] = temp;
}

void SelectionSort(int arr[], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		int min = arr[i];
		int minIndex = i;

		for (int j = i + 1; j < size; j++) 
		{
			if (arr[j] < min) 
			{
				min = arr[j];
				minIndex = j;
			}
		}

		if (i != minIndex) 
		{
			swap(arr, i, minIndex);
		}
	}
}

int countDistinctNumbers(int* arr, int size)
{
	int count = 1;
	int i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			i++;
		}
		else
		{
			count++;
			i++;
		}
	}

	return count;
}

int biggestValueIndex(int* arr, int size)
{
	int currentMax = arr[0];
	int maxIndex = 0;

	for (int i = 1; i < size; i++)
	{
		if (currentMax < arr[i])
		{
			currentMax = arr[i];
			maxIndex = i;
		}
	}

	return maxIndex;
}

int mostCommonNumber(int* arr, int n, int* distinctNumbers, int* countMatches, int size)
{
	int index = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == USED)
		{
			continue;
		}

		distinctNumbers[index] = arr[i];
		for (int j = i; j < n; j++)
		{
			if (distinctNumbers[index] == arr[j])
			{
				countMatches[index]++;
				arr[j] = USED;
			}
		}

		index++;
	}

	return distinctNumbers[biggestValueIndex(countMatches, size)];
}

int main() 
{
	int n;

	do 
	{
		std::cout << "Enter n: ";
		std::cin >> n;

	} while (n < 0 || n > 500);

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];

		while (abs(arr[i]) > 5000)
		{
			std::cout << "Please enter a number less than 5000: ";
			std::cin >> arr[i];
		}
	}

	int* temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}

	SelectionSort(temp, n);
	int size =  countDistinctNumbers(temp, n);

	delete[] temp;

	int* countMatches = new int[size];
	for (int i = 0; i < size; i++)
	{
		countMatches[i] = 0;
	}
	int* distinctNumbers = new int[size];

	std::cout << "Most common number: " << mostCommonNumber(arr, n, distinctNumbers, countMatches, size);

	delete[] arr;
	delete[] countMatches;
	delete[] distinctNumbers;

	return 0;
}