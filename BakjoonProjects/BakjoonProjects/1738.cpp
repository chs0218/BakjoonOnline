#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
BellmanFord
*/
pair<int, vector<int>> dist[101];
vector<pair<int, int>> vRoad[101];
bool bCycleNode[101];
bool bVisited[101];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vRoad[u].push_back({ v, w });
    }

    dist[1].first = 0;
    for (int i = 2; i <= n; ++i)
        dist[i].first = -1e9;

    bool bCycle = false;
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i].first == -1e9) continue;
            for (int j = 0; j < vRoad[i].size(); ++j)
            {
                int dest = vRoad[i][j].first;
                int cost = vRoad[i][j].second;

                if (dist[dest].first < dist[i].first + cost)
                {
                    dist[dest].first = dist[i].first + cost;
                    dist[dest].second = dist[i].second;
                    dist[dest].second.push_back(i);

                    if (k == n)
                    {
                        bCycle = true;
                        bCycleNode[dest] = true;
                    }
                }
            }
        }
    }

    if (bCycle)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (bCycleNode[i] && !bVisited[i])
            {
                queue<int> q;
                q.push(i);
                bVisited[i] = true;

                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();

                    for (auto& next : vRoad[cur]) {
                        int nextNode = next.first;
                        if (!bVisited[nextNode]) {
                            bVisited[nextNode] = true;
                            bCycleNode[nextNode] = true;
                            q.push(nextNode);
                        }
                    }
                }
            }
        }

        if (bCycleNode[n])
        {
            cout << "-1";
            return 0;
        }
    }

    if (dist[n].first == -1e9) cout << "-1";
    else
    {
        for (const int& i : dist[n].second)
            cout << i << " ";
        cout << n;
    }
}