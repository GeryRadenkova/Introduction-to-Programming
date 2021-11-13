#include <iostream>

const int MAX_SIZE = 1024;

bool horizontalWalk(char** tableOfLetters, int row, int col, const char* str, int N, int M)
{
	if (*str == '\0')
		return true;

	if (row < 0 || col < 0 || row >= N || col >= M || row == col)
		return false;

	if (tableOfLetters[row][col] != *str)
		return false;

	tableOfLetters[row][col] *= -1;

	bool result =
		horizontalWalk(tableOfLetters, row, col + 1, str + 1, N, M) ||
		horizontalWalk(tableOfLetters, row, col - 1, str + 1, N, M);

	tableOfLetters[row][col] *= -1;

	return result;
}

bool verticalWalk(char** tableOfLetters, int row, int col, const char* str, int N, int M)
{
	if (*str == '\0')
		return true;

	if (row < 0 || col < 0 || row >= N || col >= M || row == col)
		return false;

	if (tableOfLetters[row][col] != *str)
		return false;

	tableOfLetters[row][col] *= -1;

	bool result =
		verticalWalk(tableOfLetters, row + 1, col, str + 1, N, M) ||
		verticalWalk(tableOfLetters, row - 1, col, str + 1, N, M);

	tableOfLetters[row][col] *= -1;

	return result;
}

bool checkAboveMainDiagonal(char** tableOfLetters, const char* str, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			if (horizontalWalk(tableOfLetters, i, j, str, N, M) || verticalWalk(tableOfLetters, i, j, str, N, M))
				return true;
		}
	}

	return false;
}

bool checkUnderMainDiagonal(char** tableOfLetters, const char* str, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (horizontalWalk(tableOfLetters, i, j, str, N, M) || verticalWalk(tableOfLetters, i, j, str, N, M))
				return true;
		}
	}

	return false;
}

int main()
{
	int N, M, K;
	
	do 
	{
		std::cout << "Enter size for the table, N and M: ";
		std::cin >> N >> M;

	} while (N < 3 || M < 3 || N > 100 || M > 100 || N > M);

	std::cout << "Enter the number of words in the dictionary: ";
	std::cin >> K;


	char** tableOfLetters = new char* [N];
	for (int i = 0; i < N; i++)
	{
		tableOfLetters[i] = new char[M];
	}

	std::cout << "Enter table of chars: \n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> tableOfLetters[i][j];
		}
	}

	std::cout << std::endl;
	std::cout << "Enter words: \n";
	
	for (int i = 0; i < K; i++)
	{
		char* word = new char[MAX_SIZE];

		std::cin.getline(word, MAX_SIZE);

		if (checkAboveMainDiagonal(tableOfLetters, word, N, M) && checkUnderMainDiagonal(tableOfLetters, word, N, M))
			std::cout << "Yes\n";
		else
			std::cout << "No\n";

		delete[] word;
	}


	for (int i = 0; i < N; i++)
	{
		delete[] tableOfLetters[i];
	}
	delete[] tableOfLetters;


	return 0;
}