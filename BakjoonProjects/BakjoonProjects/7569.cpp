/*
ö���� �丶�� ���忡���� �丶�並 �����ϴ� ū â�� ������ �ִ�. 
�丶��� �Ʒ��� �׸��� ���� ���ڸ�� ������ ĭ�� �ϳ��� ���� ����, ���ڵ��� �������� �׾� �÷��� â�� �����Ѵ�.
â�� �����Ǵ� �丶��� �߿��� �� ���� �͵� ������, ���� ���� ���� �丶��鵵 ���� �� �ִ�. 
���� �� �Ϸ簡 ������, ���� �丶����� ������ ���� �ִ� ���� ���� �丶����� ���� �丶���� ������ �޾� �Ͱ� �ȴ�. 
�ϳ��� �丶�信 ������ ���� ��, �Ʒ�, ����, ������, ��, �� ���� ���⿡ �ִ� �丶�並 �ǹ��Ѵ�. 
�밢�� ���⿡ �ִ� �丶��鿡�Դ� ������ ���� ���ϸ�, �丶�䰡 ȥ�� ������ �ʹ� ���� ���ٰ� �����Ѵ�. 
ö���� â�� ������ �丶����� ��ĥ�� ������ �� �Ͱ� �Ǵ��� �� �ּ� �ϼ��� �˰� �;� �Ѵ�.
�丶�並 â�� �����ϴ� ���ڸ���� ���ڵ��� ũ��� ���� �丶���� ���� ���� �丶����� ������ �־����� ��, 
��ĥ�� ������ �丶����� ��� �ʹ���, �� �ּ� �ϼ��� ���ϴ� ���α׷��� �ۼ��϶�. 
��, ������ �Ϻ� ĭ���� �丶�䰡 ������� ���� ���� �ִ�.
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