#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int ans = 1e10;
int nSize = 0, nGoal = 0;
int nHouse = 0, nChicken = 0;
pair<int, int> houseXY[100];
pair<int, int> chickenXY[15];
bool bVisited[15];
void dfs(int depth, int previous)
{
    if (depth == nGoal) {
        int totalCost = 0;
        for (int i = 0; i < nHouse; ++i)
        {
            int d = 1e10;
            for (int j = 0; j < 15; ++j)
            {
                if (bVisited[j]) {
                    int dx = houseXY[i].second - chickenXY[j].second;
                    int dy = houseXY[i].first - chickenXY[j].first;
                    d = min(d, abs(dx) + abs(dy));
                }
            }
            totalCost += d;
        }

        if (ans > totalCost)
            ans = totalCost;
    }

    else {
        for (int i = previous + 1; i < nChicken; ++i)
        {
            if (!bVisited[i]) {
                bVisited[i] = true;
                dfs(depth + 1, i);
                bVisited[i] = false;
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> nSize >> nGoal;


    for (int i = 1; i <= nSize; ++i)
    {
        for (int j = 1; j <= nSize; ++j)
        {
            int n;
            cin >> n;

            if (n == 1) houseXY[nHouse++] = make_pair(i, j);
            if (n == 2) chickenXY[nChicken++] = make_pair(i, j);
        }
    }

    dfs(0, -1);

    cout << ans;
}