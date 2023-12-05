#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
bool bVisited[101][101];
bool bBoard[101][101];
struct Info {
    int x;
    int y;
    int cost;
};
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nHeight, nWidth;
    cin >> nHeight >> nWidth;

    for (int i = 1; i <= nHeight; ++i)
    {
        string str;
        cin >> str;

        for (int j = 1; j <= nWidth; ++j)
            bBoard[i][j] = (str[j - 1] == '1');

    }

    queue<Info> qInfo;
    bVisited[1][1] = true;
    qInfo.push(Info{ 1, 1, 1 });

    int ans = 0;
    while (!qInfo.empty()) {
        Info info = qInfo.front();
        qInfo.pop();

        if (info.y == nHeight && info.x == nWidth) {
            ans = info.cost;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nX = info.x + dx[i];
            int nY = info.y + dy[i];

            if (nX >= 1 && nX <= nWidth &&
                nY >= 1 && nY <= nHeight &&
                bBoard[nY][nX] && !bVisited[nY][nX])
            {
                bVisited[nY][nX] = true;
                qInfo.push(Info{ nX, nY, info.cost + 1 });
            }
        }
    }
    cout << ans;
}