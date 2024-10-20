#include <iostream>
#include <string>
using namespace std;
/*
Àç±Í
*/
char board[3072][6144];
void printStar(int offsetX, int offsetY, int depth)
{
	if (depth == 3) {
		board[offsetY][offsetX + 2] = '*';
		board[offsetY + 1][offsetX + 1] = '*';
		board[offsetY + 1][offsetX + 3] = '*';
		board[offsetY + 2][offsetX] = '*';
		board[offsetY + 2][offsetX + 1] = '*';
		board[offsetY + 2][offsetX + 2] = '*';
		board[offsetY + 2][offsetX + 3] = '*';
		board[offsetY + 2][offsetX + 4] = '*';
	}

	else {
		printStar(offsetX + depth / 2, offsetY, depth / 2);
		printStar(offsetX, offsetY + depth / 2, depth / 2);
		printStar(offsetX + depth, offsetY + depth / 2, depth / 2);
	}
}
int main()
{
	int input;
	cin >> input;

	printStar(0, 0, input);

	for (int i = 0; i < input; ++i)
	{
		for (int j = 0; j < input * 2; ++j)
		{
			if(board[i][j] == '\0')
				cout << " ";
			else
				cout << board[i][j];
		}
		cout << "\n";
	}
}