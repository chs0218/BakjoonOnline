#include <iostream>
#include <string>
#include <queue>
using namespace std;
bool bBoard[1001][1001];
bool bVisited[2][1001][1001];
int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
struct Info {
    int i, j, distance;
    bool bChance;
};
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        string str;
        cin >> str;

        for (int j = 1; j <= M; ++j)
            bBoard[i][j] = (str[j - 1] == '1');
    }

    queue<Info> qInfo;
    qInfo.push(Info{ 1, 1, 1, true });

    int ans = -1;
    while (!qInfo.empty())
    {
        Info info = qInfo.front();
        qInfo.pop();

        if (info.i == N && info.j == M)
        {
            ans = info.distance;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int ci = info.i + dy[i];
            int cj = info.j + dx[i];

            if (ci <= 0 || ci > N || cj <= 0 || cj > M)
                continue;

            if (info.bChance) {
                if (bBoard[ci][cj]) {
                    if (!bVisited[0][ci][cj])
                    {
                        bVisited[0][ci][cj] = true;
                        qInfo.push(Info{ ci, cj, info.distance + 1, false });
                    }
                }
                else {
                    if (!bVisited[1][ci][cj])
                    {
                        bVisited[1][ci][cj] = true;
                        qInfo.push(Info{ ci, cj, info.distance + 1, true });
                    }
                }
            }
            else {
                if (!bVisited[0][ci][cj] && !bBoard[ci][cj])
                {
                    bVisited[0][ci][cj] = true;
                    qInfo.push(Info{ ci, cj, info.distance + 1, false });
                }
            }
        }
    }
    cout << ans;
}