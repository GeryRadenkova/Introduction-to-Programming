#include <iostream>
#include <iomanip>

bool isLeapYear(int year) 
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int main()
{
	unsigned long long int egn;
	std::cout << "Enter EGN: ";
	std::cin >> egn;

	int controlNumber = egn % 10; //last number
	egn /= 10;

	int area = egn % 1000; //7th, 8th and 9th number
	egn /= 1000;

	int day = egn % 100;
	egn /= 100;

	int month = egn % 100;
	egn /= 100;

	int year = egn;


	//check the last number
	int lastNumber = ((year / 10) % 10) * 2 + (year % 10) * 4 + ((month / 10) % 10) * 8 + (month % 10) * 5
		+ ((day / 10) % 10) * 10 + (day % 10) * 9 + ((area / 100) % 10) * 7 + ((area / 10) % 10) * 3 + (area % 10) * 6;

	int res = lastNumber / 11;
	lastNumber -= (res * 11);

	if (controlNumber != lastNumber)
	{
		std::cout << "Bad input data!\n";
		return 0;
	}


	//get the year according to the month code and get the real month value
	if (month >= 1 && month <= 12)
	{
		year += 1900;
	}
	else if (month >= 21 && month <= 32)
	{
		year += 1800;
		month -= 20;
	}
	else if (month >= 41 && month <= 52)
	{
		year += 2000;
		month -= 40;
	}
	else 
	{
		std::cout << "Bad input data!\n";
		return 0;
	}
	
	
	//check if the day is correct according to the month
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (!(day >= 1 && day <= 31))
		{
			std::cout << "Bad input data!\n";
			return 0;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (!(day >= 1 && day <= 30))
		{
			std::cout << "Bad input data!\n";
			return 0;
		}
	}
	else if (isLeapYear(year))
	{
		if (!(day >= 1 && day <= 29))
		{
			std::cout << "Bad input data!\n";
			return 0;
		}
	}
	else
	{
		if (!(day >= 1 && day <= 28))
		{
			std::cout << "Bad input data!\n";
			return 0;
		}
	}


	std::cout << std::setfill('0') << std::setw(2) << day << '.'
		<< std::setfill('0') << std::setw(2) << month << '.'
		<< year << ' ';

	if ((area % 10) % 2 == 0)
		std::cout << 'M';
	else
		std::cout << 'F';

	std::cout << std::endl;


	return 0;
}
