#include <iostream>

int countSymbolsInValidWord(char* str)
{
	int count = 0;
	int i = 0;

	while ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == '-')
	{
		count++;
		i++;
	}
	
	return count;
}

void reverse(char* str, int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

void reverseWords(char* str)
{
	while (*str != '\0')
	{
		int len = countSymbolsInValidWord(str);

		if (len != 0 && len != 1)
		{
			reverse(str, len);
			str += len;
		}
		else
			str++;
		
	}
}

int main()
{
	char str[] = "Ima6å kozel v zadniq dvor na Ivan.";

	std::cout << str << std::endl;

	reverseWords(str);

	std::cout << str << std::endl;


	char str2[] = "-Da - kaza Ivan-Aleksandur.";

	std::cout << str2 << std::endl;

	reverseWords(str2);

	std::cout << str2 << std::endl;


	return 0;
}