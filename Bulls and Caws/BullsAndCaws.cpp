#include<iostream>
#include<stdlib.h> /*srand, rand*/
#include<time.h>
#include<fstream>
#include<Windows.h>

#undef max();

const int NAME_SIZE = 100;

int CheckBulls(int yourNumber, int number);
int CheckCows(int yourNumber, int numbersArr[]);
int countDigits(int num);
bool IsNumberValid(int number);
int GenerateNumber();
void PrintMenu();
void ClearScreen();
bool GotoXY(unsigned x, unsigned y);


int main() {

	srand(time(NULL));

	PrintMenu();

	int command;

	while (true) {

		std::cout << "Choose command> ";
		std::cin >> command;
		while (!std::cin) {

			std::cout << "Invalid command.\n";
			std::cout << "Choose command> ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> command;
		}

		ClearScreen();

		int numbersArr[4];

		if (command == 1 || command == 2) {

			int number;
			int yourNumber;

			if (command == 1) {

				number = GenerateNumber();

				int temp = number;  //not to change number
				for (int i = 3; i >= 0; i--) {

					numbersArr[i] = temp % 10;
					temp /= 10;
				}

				std::cout << "The computer has picked a number!\nTry to guess it.\n\n";
			}
			else if (command == 2) {

				std::cout << "Enter number> ";
				std::cin >> number;
				ClearScreen();

				while (!std::cin) {
					std::cout << "That's not a number.\n";
					std::cout << "Enter number> ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cin >> number;
					ClearScreen();
				}

				while (!IsNumberValid(number)) {
					std::cout << "Invalid number.Try again> ";
					std::cin >> number;
					ClearScreen();
				}

				int temp = number;  //not to change number
				for (int i = 3; i >= 0; i--) {

					numbersArr[i] = temp % 10;
					temp /= 10;
				}

				std::cout << "Your friend has picked a number!\nTry to guess it.\n\n";
			}

			std::cout << "    Guess    Result \n";

			//Console coordinates
			int xCoordinate = 13;
			int yCoordinate = 4;

			for (int i = 1; i < 100; i++) {

				std::cout << i << "   ";
				std::cin >> yourNumber;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (!std::cin) {
					std::cout << "That's not a number.Enter number: \n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					yCoordinate += 2;
					continue;
				}

				if (!IsNumberValid(yourNumber)) {
					std::cout << "Invalid number.Try again: \n";
					yCoordinate += 2;
					continue;
				}

				if (CheckBulls(yourNumber, number) == 4) {

					std::ofstream myfile("score.txt");
					if (!myfile.is_open()) {
						std::cout << "Unable to open file.\n";
						return 1;
					}

					GotoXY(xCoordinate, yCoordinate++);
					std::cout << "4 Bulls!\n\n";
					std::cout << "Congratulations, your score is " << 100 - i << "\n";
					myfile << "score: " << 100 - i;

					char* name = new char[NAME_SIZE];
					std::cout << "Enter your name: ";
					std::cin.getline(name, NAME_SIZE);
					myfile << " name: " << name;
					myfile.close();

					delete[] name;

					break;
				}

				GotoXY(xCoordinate, yCoordinate++);
				std::cout << CheckBulls(yourNumber, number) << " Bulls, " << CheckCows(yourNumber, numbersArr) << " Cows \n";
			}

			std::cout << "\n[0] - menu, [5] - exit \n";

		}
		else if (command == 0) {

			PrintMenu();
		}
		else if (command == 3) {

			std::ifstream file;
			file.open("score.txt");
			if (!file.is_open()) {
				std::cout << "Unable to open file.\n";
				return 1;
			}
			char c;
			do {
				file.read(&c, 1);
				if (file) {
					std::cout << c;
				}
			} while (file);
			file.close();

			std::cout << "\n\n[0] - menu, [5] - exit \n";

		}
		else if (command == 4) {

			std::cout << "One player, the Chooser, thinks of a four-digit number and the other player, the Guesser, tries to guess it.\n"
				<< "At each turn the Guesser tries a four digit number, and the Chooser says how close it is to the answer by giving :\n"
				<< "-> The number of Bulls - digits correct in the right position.\n"
				<< "-> The number of Cows - digits correct but in the wrong position.\n"
				<< "The Guesser tries to guess the answer in the fewest number of turns.You have 100 attemts.\n"
				<< "If either number has repeated digits the rule is that each digit \ncan only count towards the score once, and Bulls are counted before Cows.\n";

			std::cout << "\n[0] - menu, [5] - exit \n";

		}
		else if (command == 5) {
			break;
		}
	}

	return 0;
}

int CheckBulls(int yourNumber, int number) {

	int countBulls = 0;
	for (int i = 0; i < 4; i++) {

		if (yourNumber % 10 == number % 10) {
			countBulls++;
		}

		yourNumber /= 10;
		number /= 10;
	}

	return countBulls;
}

int CheckCows(int yourNumber, int numbersArr[]) {

	int countCows = 0;
	int digit;
	

	for (int i = 0; i < 4; i++) {

		digit = yourNumber % 10;

		if (i == 0) {
			if (digit == numbersArr[0] || digit == numbersArr[1] || digit == numbersArr[2]) {
				countCows++;
			}
		}
		else if (i == 1) {
			if (digit == numbersArr[0] || digit == numbersArr[1] || digit == numbersArr[3]) {
				countCows++;
			}
		}
		else if (i == 2) {
			if (digit == numbersArr[0] || digit == numbersArr[2] || digit == numbersArr[3]) {
				countCows++;
			}
		}
		else if (i == 3) {
			if (digit == numbersArr[1] || digit == numbersArr[2] || digit == numbersArr[3]) {
				countCows++;
			}
		}

		yourNumber /= 10;
	}

	return countCows;
}

int countDigits(int num) {

	int counter = 0;
	while (true) {

		counter++;
		num = num / 10;
		if (num == 0) {
			break;
		}
	}
	return counter;
}

bool IsNumberValid(int number) {

	if (countDigits(number) != 4) {
		return false;
	}

	int digit1, digit2, digit3, digit4;

	digit4 = number % 10;
	number /= 10;
	digit3 = number % 10;
	number /= 10;
	digit2 = number % 10;
	number /= 10;
	digit1 = number % 10;

	if (digit1 == '0') {
		return false;
	}
	else if (digit1 == digit2 || digit1 == digit3 || digit1 == digit4 || digit2 == digit3 || digit2 == digit4 || digit3 == digit4) {
		return false;
	}

	return true;
}

int GenerateNumber() {

	int digit1, digit2, digit3, digit4;

	digit1 = rand() % 10 + 1; //in the range 1 to 10

	do {
		digit2 = rand() % 10; //in the range 0 to 9
	} while (digit1 == digit2);

	do {
		digit3 = rand() % 10;
	} while (digit3 == digit1 || digit3 == digit2);

	do {
		digit4 = rand() % 10;
	} while (digit4 == digit1 || digit4 == digit2 || digit4 == digit3);

	int number;
	number = 1000 * digit1 + 100 * digit2 + 10 * digit3 + digit4;

	return number;
}

void PrintMenu() {

	std::cout << "  * Bulls and Cows Game * \n";
	std::cout << "0 - Show Menu\n";
	std::cout << "1 - Play with the computer\n";
	std::cout << "2 - Play with a friend\n";
	std::cout << "3 - See scores\n";
	std::cout << "4 - Description\n";
	std::cout << "5 - Exit program\n";
}

void ClearScreen() {

	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

bool GotoXY(unsigned x, unsigned y) {

	COORD position = { x, y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
