#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001];
int cost[1001][1001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct Info {
    int x;
    int y;
    int cost;
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nWidth, nHeight;
    cin >> nHeight >> nWidth;

    queue<Info> qInfo;
    for (int i = 0; i < nHeight; ++i)
    {
        for (int j = 0; j < nWidth; ++j)
        {
            cin >> map[i][j];

            if (map[i][j] == 1) cost[i][j] = -1;
            else if (map[i][j] == 2)
            {
                cost[i][j] = 0;
                qInfo.push(Info{ j, i, 0 });
            }
            else cost[i][j] = 0;
        }
    }

    while (!qInfo.empty()) {
        Info info = qInfo.front();
        qInfo.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = info.x + dx[i];
            int ny = info.y + dy[i];

            if (nx < 0 || nx >= nWidth || ny < 0 || ny >= nHeight)
                continue;

            if (cost[ny][nx] == -1) {
                cost[ny][nx] = info.cost + 1;
                qInfo.push(Info{ nx, ny, info.cost + 1 });
            }
        }
    }

    for (int i = 0; i < nHeight; ++i)
    {
        for (int j = 0; j < nWidth; ++j)
            cout << cost[i][j] << " ";
        cout << "\n";
    }
}