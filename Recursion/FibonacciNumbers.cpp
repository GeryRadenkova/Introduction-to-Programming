#include<iostream>

int Fibonacci(int n) {

	if (n == 0 || n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {

	int n;
	std::cout << "n> ";
	std::cin >> n;
	std::cout << "Fibonacci(" << n << ") = ";
	std::cout << Fibonacci(n) << std::endl;

	return 0;
}