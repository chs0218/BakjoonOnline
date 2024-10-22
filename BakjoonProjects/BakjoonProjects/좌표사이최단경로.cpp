#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool bVisited[31][31];

bool bIsValid(int x, int y)
{
    if (x < 0) return false;
    if (y < 0) return false;
    if (x > 30) return false;
    if (y > 30) return false;
    if (y > x) return false;
}

int main() {
    int H, N;
    cin >> H >> N;

    priority_queue<tuple<int, pair<int, int>>> q;
    q.push({ 0, {H, H} });

    int ans = 0;
    while (!q.empty())
    {
        tuple<int, pair<int, int>> cur = q.top();
        int curValue = get<0>(cur);
        pair<int, int> coord = get<1>(cur);
        q.pop();

        bVisited[coord.first][coord.second] = true;
        if (coord.first == N && coord.second == N)
        {
            ++ans;
            continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            int newY = coord.first + dy[i];
            int newX = coord.second + dx[i];
            int newValue = curValue + 1;

            if (bIsValid(newX, newY))
            {
                q.push({ newValue, {newY, newX} });
            }
        }
    }
    cout << ans;
    return 0;
}