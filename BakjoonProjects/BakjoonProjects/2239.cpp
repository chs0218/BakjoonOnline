#include <iostream>
#include <string>
using namespace std;
/*
구현
백트래킹
*/
int board[9][9];
int column[9][10];
int row[9][10];
int block[9][10];
void dfs(int n)
{
    if (n == 81) {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
                cout << board[i][j];
            cout << "\n";
        }
        exit(0);
    }

    int curX = n % 9;
    int curY = n / 9;

    if (board[curY][curX] == 0) {
        for (int i = 1; i < 10; ++i)
        {
            if (!column[curY][i] && !row[curX][i]
                && !block[(curY / 3) * 3 + curX / 3][i])
            {
                column[curY][i] = true;
                row[curX][i] = true;
                block[(curY / 3) * 3 + curX / 3][i] = true;
                board[curY][curX] = i;
                dfs(n + 1);
                board[curY][curX] = 0;
                column[curY][i] = false;
                row[curX][i] = false;
                block[(curY / 3) * 3 + curX / 3][i] = false;
            }
        }
    }
    else dfs(n + 1);
}
int main()
{
    for (int i = 0; i < 9; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = str[j] - '0';
            column[i][board[i][j]] = true;
            row[j][board[i][j]] = true;
            block[(i / 3) * 3 + j / 3][board[i][j]] = true;
        }
    }

    dfs(0);
}