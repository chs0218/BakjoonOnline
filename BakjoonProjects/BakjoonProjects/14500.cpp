#include <iostream>
using namespace std;
int paper[501][501];
bool bVisited[501][501];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int nHeight = 0, nWidth = 0;
int ans = 0;
void dfs(int i, int j, int n, int sum)
{
    sum += paper[i][j];

    if (n == 3) {
        ans = max(ans, sum);
        return;
    }

    for (int k = 0; k < 4; ++k)
    {
        int nx = j + dx[k];
        int ny = i + dy[k];

        if (nx < 0 || nx >= nWidth || ny < 0 || ny >= nHeight)
            continue;

        if (!bVisited[ny][nx]) {
            bVisited[ny][nx] = true;
            dfs(ny, nx, n + 1, sum);
            bVisited[ny][nx] = false;
        }
    }
}
void chkexcept(int i, int j)
{
    if (i + 1 < nHeight && j + 2 < nWidth) {
        int n = paper[i][j] + paper[i][j + 1] +
            paper[i][j + 2] + paper[i + 1][j + 1];
        ans = max(ans, n);
    }

    if (i - 1 >= 0 && j + 2 < nWidth) {
        int n = paper[i][j] + paper[i][j + 1] +
            paper[i][j + 2] + paper[i - 1][j + 1];
        ans = max(ans, n);
    }

    if (i + 2 < nHeight && j + 1 < nWidth) {
        int n = paper[i][j] + paper[i + 1][j] +
            paper[i + 2][j] + paper[i + 1][j + 1];
        ans = max(ans, n);
    }

    if (i + 2 < nHeight && j - 1 >= 0) {
        int n = paper[i][j] + paper[i + 1][j] +
            paper[i + 2][j] + paper[i + 1][j - 1];
        ans = max(ans, n);
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> nHeight >> nWidth;

    for (int i = 0; i < nHeight; ++i)
    {
        for (int j = 0; j < nWidth; ++j)
            cin >> paper[i][j];
    }


    for (int i = 0; i < nHeight; ++i)
    {
        for (int j = 0; j < nWidth; ++j)
        {
            bVisited[i][j] = true;
            dfs(i, j, 0, 0);
            bVisited[i][j] = false;
            chkexcept(i, j);
        }
    }

    cout << ans;
}