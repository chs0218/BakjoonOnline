#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool bVisited[25][25];
bool bIsHouse[25][25];

int nWidth = 0;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs(int i, int j)
{
    int ret = 1;

    queue<pair<int, int>> qXY;
    qXY.push(make_pair(i, j));
    while (!qXY.empty())
    {
        pair<int, int> pXY = qXY.front();
        qXY.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nY = pXY.first + dy[i];
            int nX = pXY.second + dx[i];

            if (nX < 0 || nX >= nWidth || nY < 0 || nY >= nWidth)
                continue;

            if (bIsHouse[nY][nX] && !bVisited[nY][nX])
            {
                ++ret;
                bVisited[nY][nX] = true;
                qXY.push(make_pair(nY, nX));
            }
        }
    }

    return ret;
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> nWidth;

    queue<pair<int, int>> qHouseXY;
    for (int i = 0; i < nWidth; ++i)
    {
        string str;
        cin >> str;

        for (int j = 0; j < nWidth; ++j)
        {
            if (str[j] == '1')
            {
                bIsHouse[i][j] = true;
                qHouseXY.push(make_pair(i, j));
            }
        }
    }

    vector<int> vHousing;
    while (!qHouseXY.empty()) {
        pair<int, int> curXY = qHouseXY.front();
        qHouseXY.pop();

        if (!bVisited[curXY.first][curXY.second])
        {
            bVisited[curXY.first][curXY.second] = true;
            vHousing.push_back(bfs(curXY.first, curXY.second));
        }
    }

    sort(vHousing.begin(), vHousing.end());

    cout << vHousing.size() << "\n";
    for (const int& n : vHousing)
        cout << n << "\n";
}