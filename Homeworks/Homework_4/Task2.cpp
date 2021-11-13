#include <iostream>

int countWordOccurrences(const char* str, const char* word)
{
	int count = 0;

	while (*str != '\0')
	{
		const char* temp = word;
		while (*word != '\0' && *str == *word)
		{
			str++;
			word++;
		}

		if (*word == '\0')
			count++;

		word = temp;
		str++;
	}

	return count;
}

bool findWord(const char* str, const char* word)
{
	while (*word != '\0' && *str == *word)
	{
		str++;
		word++;
	}

	return *word == '\0';
}

char* stringReplace(const char* str, const char* what, const char* with)
{
	int count = countWordOccurrences(str, what);
	int len = strlen(str) + ((strlen(with) - strlen(what)) * count);

	char* resultStr = new char[len + 1];
	int ind = 0;

	while (*str != '\0')
	{
		if (*str == *what && findWord(str, what))
		{
			int i = 0;
			while (with[i] != '\0')
			{
				resultStr[ind++] = with[i++];
			}

			str += strlen(what);
		}
		else
		{
			resultStr[ind++] = *str;
			str++;
		}
	}
	
	resultStr[ind] = '\0';

	return resultStr;
}

int main()
{
	const char* str = "My dog is very clever dog.";
	const char* word = "dog";
	std::cout << stringReplace(str, word, "parrot");

	return 0;
}