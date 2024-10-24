#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
/*
다익스트라 알고리즘
*/
const double RunSpeed = 5.0f;
double dist[102];
pair<double, double> loc[102];
double CalCannonCost(double curCost, int curIndex, int nextIndex)
{
    double xDiff = fabs(loc[nextIndex].first - loc[curIndex].first);
    double yDiff = fabs(loc[nextIndex].second - loc[curIndex].second);
    double dist = hypot(xDiff, yDiff);
    
    return curCost + fabs(dist - 50.0f) / RunSpeed + 2.0f;
}
double CalRunCost(double curCost, int curIndex, int nextIndex)
{
    double xDiff = fabs(loc[nextIndex].first - loc[curIndex].first);
    double yDiff = fabs(loc[nextIndex].second - loc[curIndex].second);
    double dist = hypot(xDiff, yDiff);

    return curCost + dist / RunSpeed;
}
int main()
{
    pair<double, double> start, dest;
    cin >> start.first >> start.second;
    cin >> dest.first >> dest.second;

    int n;
    cin >> n;

    loc[0] = start;
    loc[n + 1] = dest;
    for (int i = 1; i <= n; ++i)
    {
        cin >> loc[i].first >> loc[i].second;
    }


    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    
    dist[0] = 0.0f;
    for (int i = 1; i <= n + 1; ++i)
    {
        double newDist = CalRunCost(0.0f, 0, i);
        dist[i] = newDist;
        pq.push({ dist[i], i });
    }

    while (!pq.empty())
    {
        double curCost;
        int curIndex;
        tie(curCost, curIndex) = pq.top();
        pq.pop();

        if (dist[curIndex] < curCost) continue;

        for (int i = 1; i <= n + 1; ++i)
        {
            if (i == curIndex) continue;
            double newRunCost = CalRunCost(curCost, curIndex, i);
            double newCannonCost = CalCannonCost(curCost, curIndex, i);
            double newCost = min(newRunCost, newCannonCost);
            if (newCost < dist[i])
            {
                dist[i] = newCost;
                pq.push({ dist[i], i });
            }
        }
    }
    cout << dist[n + 1];
}