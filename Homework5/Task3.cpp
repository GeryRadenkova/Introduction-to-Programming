#include <iostream>

char buff[4];
void PrintVariationsWithRep(char* arr, char* free, int n, int k, int index) {

	if (index >= k) {
		for (int i = 0; i < k; i++)
			std::cout << free[i];
		std::cout << std::endl;
		std::cout << "Do you want another password? Yes/No: ";
		std::cin.getline(buff,4);
		if (!strcmp(buff,"No")) 
			return;
	}
	else {
		for (int i = 0; i < n; i++) {
			free[index] = arr[i];
			if (!strcmp(buff, "No"))
				return;
		
			PrintVariationsWithRep(arr, free, n, k, index + 1);
		}
		std::cout << "No more;(";
	}
}

int main() {
	char arr[] = { "abcdefghijklmnopqrstuvwxyz_" };

	int X;
	do {
		std::cout << "Enter X: ";
		std::cin >> X;
		char c = std::cin.get(); //to get '\n'
	} while (X < 1 || X > 10);

	char* free = new char[X + 1]; //vsichki naredeni X-orki s elementi ot arr shte pazim tuk
	free[X] = '\0';
	PrintVariationsWithRep(arr, free, 27, X, 0);
	delete[] free;
}