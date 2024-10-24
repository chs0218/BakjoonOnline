#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int n;
int grid[2222][2222];
int cost[2222][2222];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
            cost[i][j] = 1e9;
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    cost[0][0] = 0;
    pq.push({ 0, 0, 0 });

    while (!pq.empty())
    {
        int curCost, curY, curX;
        tie(curCost, curY, curX) = pq.top();
        pq.pop();

        if (cost[curY][curX] < curCost) continue;

        if (curY == n - 1 && curX == n - 1) break;
        if (curY != n - 1)
        {
            int nextCost = (grid[curY][curX] > grid[curY + 1][curX]) ? curCost : curCost + (grid[curY + 1][curX] - grid[curY][curX]) + 1;
            if (cost[curY + 1][curX] > nextCost)
            {
                cost[curY + 1][curX] = nextCost;
                pq.push({ nextCost, curY + 1, curX });
            }
        }
        if (curX != n - 1)
        {
            int nextCost = (grid[curY][curX] > grid[curY][curX + 1]) ? curCost : curCost + (grid[curY][curX + 1] - grid[curY][curX]) + 1;
            if (cost[curY][curX + 1] > nextCost)
            {
                cost[curY][curX + 1] = nextCost;
                pq.push({ nextCost, curY, curX + 1 });
            }
        }
    }
    cout << cost[n - 1][n - 1];
}