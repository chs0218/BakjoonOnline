#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
/*
구현
그래프 이론
그래프 탐색
시뮬레이션
너비 우선 탐색
깊이 우선 탐색
*/
int N, M;
int board[100][100];
bool bOutside[100][100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void SetOutside()
{
    memset(bOutside, false, sizeof(bOutside));

    queue<pair<int, int>> qXY;
    bOutside[0][0] = true;
    qXY.push(make_pair(0, 0));

    while (!qXY.empty()) {
        int curi = qXY.front().first;
        int curj = qXY.front().second;
        qXY.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ni = curi + dy[i];
            int nj = curj + dx[i];

            if (ni < 0 || ni >= N || nj < 0 || nj >= M)
                continue;

            if (!bOutside[ni][nj] && !board[ni][nj]) {
                bOutside[ni][nj] = true;
                qXY.push(make_pair(ni, nj));
            }
        }
    }
}
void meltCheese()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == 1) {
                int nSide = 0;

                for (int k = 0; k < 4; ++k)
                {
                    int ni = i + dy[k];
                    int nj = j + dx[k];

                    if (bOutside[ni][nj]) ++nSide;
                }

                if (nSide >= 2) board[i][j] = 0;
            }
        }
}
bool CheckCheese()
{
    bool ret = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 1) {
                ret = false;
                break;
            }
        }
        if (!ret) break;
    }
    return ret;
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    int ans = 0;
    while (1) {
        if (CheckCheese()) break;

        ++ans;
        SetOutside();
        meltCheese();
    }
    cout << ans;
}