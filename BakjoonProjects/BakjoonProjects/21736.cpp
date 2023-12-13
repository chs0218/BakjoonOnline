#include <iostream>
#include <string>
#include <queue>
using namespace std;
char campus[600][600];
bool bVisited[600][600];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nWidth, nHeight;
    cin >> nHeight >> nWidth;

    int nStartX = -1, nStartY = -1;
    for (int i = 0; i < nHeight; ++i)
    {
        string str;
        cin >> str;

        for (int j = 0; j < nWidth; ++j)
        {
            campus[i][j] = str[j];

            if (campus[i][j] == 'I') {
                nStartX = j;
                nStartY = i;
            }
        }
    }

    queue<pair<int, int>> qInfo;
    bVisited[nStartY][nStartX] = true;
    qInfo.push(make_pair(nStartY, nStartX));

    int ans = 0;
    while (!qInfo.empty()) {
        pair<int, int> info = qInfo.front();
        qInfo.pop();

        if (campus[info.first][info.second] == 'X')
            continue;

        if (campus[info.first][info.second] == 'P')
            ++ans;

        for (int i = 0; i < 4; ++i) {
            int nx = info.second + dx[i];
            int ny = info.first + dy[i];

            if (0 > nx || nx >= nWidth || 0 > ny || ny >= nHeight)
                continue;

            if (!bVisited[ny][nx]) {
                bVisited[ny][nx] = true;
                qInfo.push(make_pair(ny, nx));
            }
        }
    }

    if (ans) cout << ans;
    else cout << "TT";
}