#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N, M;
char MAP[1001][1001];
int bVisited[1001][1001];
bool dfs(int c, int r)
{
    if (bVisited[c][r] == 1) return true;
    if (bVisited[c][r] == 2) return false;

    int nextc = c, nextr = r;

    if (MAP[c][r] == 'U')
        nextc = c - 1;
    if (MAP[c][r] == 'D')
        nextc = c + 1;
    if (MAP[c][r] == 'L')
        nextr = r - 1;
    if (MAP[c][r] == 'R')
        nextr = r + 1;

    bool ret = true;
    bVisited[c][r] = 1;
    ret = dfs(nextc, nextr);
    bVisited[c][r] = 2;
    return ret;
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;

        for (int j = 0; j < M; ++j)
            MAP[i][j] = str[j];
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (bVisited[i][j] == 0 && dfs(i, j))
                ++ans;
        }
    }
    cout << ans;
}