#include <iostream>

const int MAX_SIZE = 1024;

bool isBeautifulLine(unsigned int** matrix, unsigned int lineSize, unsigned int line);
unsigned int* concat(unsigned int** matrix, unsigned int line, size_t size, unsigned int N, unsigned int temp[]);
void clean(unsigned int** matrix, int m);

int main() {

	unsigned int M;
	unsigned int N;
	std::cin >> M >> N;

	unsigned int** matrix = new(std::nothrow) unsigned int*[M];
	if (!matrix) {

		std::cout << "Fail to allocate memory.";
		return 1;
	}

	for (int i = 0; i < M; ++i) {

		matrix[i] = new(std::nothrow) unsigned int[N];
		if (!matrix[i]) {

			clean(matrix, i);
			std::cout << "Fail to allocate memory.";
			return 1;
		}

		for (int j = 0; j < N; ++j)
			std::cin >> matrix[i][j];
	}

	unsigned int temp[MAX_SIZE];
	size_t size = 0;
	for (int i = 0; i < M; ++i) {

		if (isBeautifulLine(matrix, N, i)) {

			size += N;
			concat(matrix, i, size, N, temp);
		}
	}

	unsigned int* arr = new(std::nothrow) unsigned int[size]; //to have an accurate length
	if (!arr) {

		std::cout << "Fail to allocate memory.";
		return 1;
	}

	for (int i = 0; i < size; ++i)
		arr[i] = temp[i];

	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";

	delete[] arr;
	clean(matrix, M);

	return 0;
}

unsigned int* concat(unsigned int** matrix, unsigned int line,size_t size,unsigned int N,unsigned int temp[]) {

	int j = 0;
	for (int i = size - N; i < size; ++i) 
		temp[i] = matrix[line][j++];

	return temp;
}

bool isBeautifulLine(unsigned int** matrix, unsigned int lineSize, unsigned int line) {

	int count = 0;
	for (int i = 0; i < lineSize; ++i) {

		for (int k = 0; k < 32; ++k) {

			if (matrix[line][i] & (1 << k))
				++count;
		}
	}
	if (count % 2 == 0)
		return true;

	return false;
}

void clean(unsigned int** matrix, int m) {

	for (int i = m - 1; i >= 0; --i)
		delete[] matrix[i];

	delete[] matrix;
}