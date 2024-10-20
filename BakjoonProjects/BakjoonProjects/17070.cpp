#include <iostream>
#include <queue>
using namespace std;
/*
다이나믹 프로그래밍
그래프 이론
그래프 탐색
*/
struct Pipe {
    int r, c, shape;
};
int N;
int house[16][16];
bool bChk(int r, int c)
{
    if (0 > r || r >= N || 0 > c || c >= N)
        return false;
    if (house[r][c] != 0)
        return false;
    return true;
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> house[i][j];

    queue<Pipe> q;
    q.push({ 0, 1, 0 });

    int ans = 0;
    while (!q.empty())
    {
        Pipe cur = q.front();
        q.pop();

        if (cur.r == N - 1 && cur.c == N - 1)
        {
            ++ans;
            continue;
        }

        switch (cur.shape)
        {
        case 0:
            if (bChk(cur.r, cur.c + 1))
            {
                q.push({ cur.r, cur.c + 1, 0 });

                if (bChk(cur.r + 1, cur.c) &&
                    bChk(cur.r + 1, cur.c + 1))
                    q.push({ cur.r + 1, cur.c + 1, 2 });
            }
            break;
        case 1:
            if (bChk(cur.r + 1, cur.c))
            {
                q.push({ cur.r + 1, cur.c, 1 });
                if (bChk(cur.r, cur.c + 1) && bChk(cur.r + 1, cur.c + 1))
                    q.push({ cur.r + 1, cur.c + 1, 2 });
            }
            break;
        case 2:
            if (bChk(cur.r, cur.c + 1))
                q.push({ cur.r, cur.c + 1, 0 });
            if (bChk(cur.r + 1, cur.c))
                q.push({ cur.r + 1, cur.c, 1 });
            if (bChk(cur.r + 1, cur.c) &&
                bChk(cur.r, cur.c + 1) &&
                bChk(cur.r + 1, cur.c + 1))
                q.push({ cur.r + 1, cur.c + 1, 2 });
            break;
        }
    }
    cout << ans;
}