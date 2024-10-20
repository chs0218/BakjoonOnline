#include <iostream>
using namespace std;
/*
다이나믹 프로그래밍
누적 합
*/
int info[1025][1025];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nSize, nOperate;
    cin >> nSize >> nOperate;

    for (int i = 1; i <= nSize; ++i)
    {
        for (int j = 1; j <= nSize; ++j)
        {
            cin >> info[i][j];
            info[i][j] = info[i - 1][j] + info[i][j - 1] +
                info[i][j] - info[i - 1][j - 1];
        }
    }

    for (int i = 0; i < nOperate; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = info[x2][y2] - info[x1 - 1][y2]
            - info[x2][y1 - 1] + info[x1 - 1][y1 - 1];

        cout << ans << "\n";
    }
}