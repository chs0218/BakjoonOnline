#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
/*
구현
그래프 이론
그래프 탐색
시뮬레이션
너비 우선 탐색
*/
int space[20][20];
bool visited[20][20];
int dx[4] = { 0, -1, 1, 0 };
int dy[4] = { -1, 0, 0, 1 };
int N = 0, sharkSize = 2;
int sharkStack = 2;
pair<int, int> sharkXY;
struct state {
    pair<int, int> xy;
    int dist;
};
bool operator<(state lhs, state rhs)
{
    if (lhs.dist == rhs.dist)
    {
        if (lhs.xy.first == rhs.xy.first)
            return lhs.xy.second > rhs.xy.second;
        else
            return lhs.xy.first > rhs.xy.first;
    }
    return lhs.dist > rhs.dist;
}
int simulate()
{
    int ret = 0;

    priority_queue<state> q;
    memset(visited, false, sizeof(visited));
    visited[sharkXY.first][sharkXY.second] = true;
    q.push({ sharkXY, 0 });

    while (!q.empty())
    {
        pair<int, int> xy = q.top().xy;
        int dist = q.top().dist;
        q.pop();

        if (0 < space[xy.first][xy.second] &&
            space[xy.first][xy.second] < sharkSize)
        {
            sharkXY.first = xy.first;
            sharkXY.second = xy.second;
            space[xy.first][xy.second] = 0;
            if (--sharkStack == 0)
            {
                ++sharkSize;
                sharkStack = sharkSize;
            }
            ret = dist;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> nextXY = make_pair(xy.first + dy[i], xy.second + dx[i]);
            if (0 > nextXY.first || nextXY.first >= N ||
                0 > nextXY.second || nextXY.second >= N)
                continue;

            if (!visited[nextXY.first][nextXY.second] && 
                space[nextXY.first][nextXY.second] <= sharkSize)
            {
                visited[nextXY.first][nextXY.second] = true;
                q.push({ nextXY, dist + 1 });
            }
        }
    }
    return ret;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> space[i][j];

            if (space[i][j] == 9)
            {
                space[i][j] = 0;
                sharkXY.first = i;
                sharkXY.second = j;
            }
        }

    int ans = 0;
    while (1)
    {
        int ret = simulate();
        if (ret == 0) break;
        ans += ret;
    }
    cout << ans;
}