#include <iostream>
using namespace std;
int board[50][50];
int update[50][50];
int R, C, T;
int puriY1 = -1, puriY2 = -1;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void UpdateBoard()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            if (update[i][j] > 0) {
                if (board[i][j] != -1) board[i][j] += update[i][j];
                update[i][j] = 0;
            }
        }
}
void Expand()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            int n = 0;
            if (board[i][j] > 0) {
                for (int k = 0; k < 4; ++k) {
                    int nextY = i + dy[k];
                    int nextX = j + dx[k];

                    if (nextY < 0 || nextY >= R
                        || nextX < 0 || nextX >= C)
                        continue;

                    if (board[nextY][nextX] != -1) {
                        update[nextY][nextX] += board[i][j] / 5;
                        ++n;
                    }
                }
            }
            board[i][j] -= board[i][j] / 5 * n;
        }

    UpdateBoard();
}
void Purify()
{
    for (int i = 1; i < C - 1; ++i) {
        if (board[puriY1][i] > 0) {
            update[puriY1][i + 1] += board[puriY1][i];
            board[puriY1][i] = 0;
        }
        if (board[puriY2][i] > 0) {
            update[puriY2][i + 1] += board[puriY2][i];
            board[puriY2][i] = 0;
        }
        if (board[0][i] > 0) {
            update[0][i - 1] += board[0][i];
            board[0][i] = 0;
        }
        if (board[R - 1][i] > 0) {
            update[R - 1][i - 1] += board[R - 1][i];
            board[R - 1][i] = 0;
        }
    }
    for (int i = 0; i < R; ++i) {
        if (i <= puriY1) {
            if (board[i][0] > 0) {
                update[i + 1][0] += board[i][0];
                board[i][0] = 0;
            }
            if (board[i][C - 1] > 0) {
                if (i == 0) {
                    update[i][C - 2] += board[i][C - 1];
                    board[i][C - 1] = 0;
                }
                else {
                    update[i - 1][C - 1] += board[i][C - 1];
                    board[i][C - 1] = 0;
                }
            }
        }
        else {
            if (board[i][C - 1] > 0) {
                if (i == R - 1) {
                    update[i][C - 2] += board[i][C - 1];
                    board[i][C - 1] = 0;
                }
                else {
                    update[i + 1][C - 1] += board[i][C - 1];
                    board[i][C - 1] = 0;
                }
            }
            if (board[i][0] > 0) {
                update[i - 1][0] += board[i][0];
                board[i][0] = 0;
            }
        }
    }
    UpdateBoard();
}
int main()
{
    cin >> R >> C >> T;

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                if (puriY1 == -1) puriY1 = i;
                else puriY2 = i;
            }
        }

    for (int i = 0; i < T; ++i)
    {
        Expand();
        Purify();
    }
    
    int ans = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] > 0)
                ans += board[i][j];
    cout << ans;
}