#include <iostream>
#include <memory.h>
#include <string>
#include <queue>
using namespace std;
int R, C;
char board[20][20];
bool bVisited[26];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans = 0;
void dfs(int curX, int curY, int dist)
{
    if (ans < dist) ans = dist;

    for (int i = 0; i < 4; ++i)
    {
        int ny = curY + dy[i];
        int nx = curX + dx[i];

        if (nx < 0 || nx >= C || ny < 0 || ny >= R)
            continue;

        if (!bVisited[board[ny][nx] - 'A']) {
            bVisited[board[ny][nx] - 'A'] = true;
            dfs(nx, ny, dist + 1);
            bVisited[board[ny][nx] - 'A'] = false;
        }
    }
}
int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; ++i)
    {
        string str;
        cin >> str;

        for (int j = 0; j < C; ++j)
            board[i][j] = str[j];
    }

    bVisited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    bVisited[board[0][0] - 'A'] = false;

    cout << ans;
}