/*
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 
토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 넣은 다음, 상자들을 수직으로 쌓아 올려서 창고에 보관한다.
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
*/

#include <iostream>
#include <queue>
using namespace std;
int nBoxInfo[100][100][100];
bool bVisited[100][100][100];
struct TomatoInfo {
    int x;
    int y;
    int z;
    int cost;
};
int dx[] = { -1, 1, 0, 0, 0, 0 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    queue<TomatoInfo> qTomato;
    int nX, nY, nZ;
    cin >> nX >> nZ >> nY;

    for (int i = 0; i < nY; ++i)
    {
        for (int j = 0; j < nZ; ++j)
        {
            for (int k = 0; k < nX; ++k)
            {
                cin >> nBoxInfo[i][j][k];
                if (nBoxInfo[i][j][k] == 1)
                {
                    qTomato.push(TomatoInfo{ k, i, j, 0 });
                    bVisited[i][j][k] = true;
                }
                else if (nBoxInfo[i][j][k] == -1)
                    bVisited[i][j][k] = true;
            }
        }
    }

    int cost = 0;
    while (!qTomato.empty())
    {
        TomatoInfo info = qTomato.front();
        qTomato.pop();
        cost = max(cost, info.cost);

        for (int i = 0; i < 6; ++i)
        {
            int x = info.x + dx[i];
            int y = info.y + dy[i];
            int z = info.z + dz[i];

            if (x >= 0 && x < nX && y >= 0 && y < nY && z >= 0 && z < nZ && !bVisited[y][z][x])
            {
                qTomato.push(TomatoInfo{ x, y, z, info.cost + 1 });
                bVisited[y][z][x] = true;
            }
        }
    }

    for (int i = 0; i < nY; ++i)
    {
        for (int j = 0; j < nZ; ++j)
        {
            for (int k = 0; k < nX; ++k)
            {
                if (!bVisited[i][j][k])
                {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    cout << cost << "\n";
    return 0;
}