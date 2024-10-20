#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
/*
구현
그래프 이론
브루트포스 알고리즘
그래프 탐색
너비 우선 탐색
*/
int map[8][8];
int chk[8][8];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
vector<pair<int, int>> vBlank;
vector<pair<int, int>> vVirus;
int CalSafe(){
    int ret = 0;
    
    queue<pair<int, int>> qVirus;
    for (int i = 0; i < vVirus.size(); ++i)
        qVirus.push({ vVirus[i].first, vVirus[i].second });

    while (!qVirus.empty())
    {
        int curX = qVirus.front().second;
        int curY = qVirus.front().first;
        qVirus.pop();

        for (int i = 0; i < 4; ++i) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
                continue;

            if (chk[nextY][nextX] == 0)
            {
                chk[nextY][nextX] = 2;
                qVirus.push({ nextY, nextX });
            }
        }
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (chk[i][j] == 0) ++ret;

    return ret;
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
        {
            if (i < N && j < M) {
                cin >> map[i][j];
                if (map[i][j] == 0) vBlank.push_back({ i, j });
                else if (map[i][j] == 2) vVirus.push_back({ i, j });
            }
            else map[i][j] = -1;
        }

    int ans = 0;
    for (int i = 0; i < vBlank.size() - 2; ++i)
    {
        for (int j = i + 1; j < vBlank.size() - 1; ++j)
        {
            for (int k = j + 1; k < vBlank.size(); ++k)
            {
                memcpy(chk, map, sizeof(chk));
                chk[vBlank[i].first][vBlank[i].second] = 1;
                chk[vBlank[j].first][vBlank[j].second] = 1;
                chk[vBlank[k].first][vBlank[k].second] = 1;
                ans = max(ans, CalSafe());
            }
        }
    }
    cout << ans;
}