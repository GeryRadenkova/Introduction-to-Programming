#include <iostream>

int main()
{
	char chessPiece;
	std::cin >> chessPiece;

	if (chessPiece != 'B' && chessPiece != 'Q' && chessPiece != 'R' && chessPiece != 'N')
	{
		std::cout << "Invalid chess piece. \n";
		return 0;
	}

	char x1;  // the attacking figure coordinates
	int y1;
	std::cin >> x1 >> y1;
	char c = std::cin.get(); //to get '\n'
	

	char x2; // the king figure coordinates
	int y2;
	std::cin >> x2 >> y2;

	if (!(x1 >= 'a' && x1 <= 'h') || !(y1 >= 1 && y1 <= 8) || !(x2 >= 'a' && x2 <= 'h') || !(y2 >= 1 && y2 <= 8))
	{
		std::cout << "Invalid coordinates\n";
		return 0;
	}


	if (chessPiece == 'B' || chessPiece == 'Q')
	{
		if (x1 < x2 && y1 < y2 && x2 - x1 == y2 - y1)
		{
			std::cout << "Yes\n"; 
			return 0;
		}
		else if (x1 > x2 && y1 > y2 && x1 - x2 == y1 - y2)
		{
			std::cout << "Yes\n";
			return 0;
		}
		else if (x1 > x2 && y1 < y2 && x1 - x2 == y2 - y1)
		{
			std::cout << "Yes\n";
			return 0;
		}
		else if (x1 < x2 && y1 > y2 && x2 - x1 == y1 - y2)
		{
			std::cout << "Yes\n";
			return 0;
		}
	}

	if (chessPiece == 'R' || chessPiece == 'Q')
	{
		if (x2 == x1 || y2 == y1)
			std::cout << "Yes\n"; return 0;
	}

	if (chessPiece == 'N')
	{
		if (x1 + 2 == x2 && (y1 + 1 == y2 || y1 - 1 == y2))
		{
			std::cout << "Yes\n";
			return 0;
		}
		else if (x1 - 2 == x2 && (y1 + 1 == y2 || y1 - 1 == y2))
		{
			std::cout << "Yes\n";
			return 0;
		}
		else if (y1 + 2 == y2 && (x1 + 1 == x2 || x1 - 1 == x2))
		{
			std::cout << "Yes\n";
			return 0;
		}
		else if (y1 - 2 == y2 && (x1 + 1 == x2 || x1 - 1 == x2))
		{
			std::cout << "Yes\n";
			return 0;
		}
	}
	
	std::cout << "No\n";

	return 0;
}
