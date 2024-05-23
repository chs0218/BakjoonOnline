#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> vEdge[10001];
int dist[10001];
int N, D;
int main()
{
    cin >> N >> D;

    for (int i = 0; i < D; ++i)
        vEdge[i].push_back({ i + 1, 1 });

    for (int i = 0; i < N; ++i)
    {
        int start, end, length;
        cin >> start >> end >> length;
        vEdge[start].push_back({ end, length });
    }

    for (int i = 0; i < 10001; ++i)
        dist[i] = 1e9;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqInfo;
    pqInfo.push({ 0, 0 });
    dist[0] = 0;

    while (!pqInfo.empty()) {
        int cur = pqInfo.top().second;
        int cost = pqInfo.top().first;
        pqInfo.pop();

        if (cost > dist[cur])
            continue;

        for (const pair<int, int>& edge : vEdge[cur])
        {
            pair<int, int> next = { cost + edge.second, edge.first };
            if (next.first < dist[next.second])
            {
                dist[next.second] = next.first;
                pqInfo.push(next);
            }
        }
    }

    cout << dist[D];
}