#include <iostream>
#include <vector>
using namespace std;
/*
벨만포드
*/
int dist[20000];
int prevPoints[20000];
vector<pair<int, int>> vEdge[20000];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vEdge[a].push_back({ b, c });
    }

    for (int i = 0; i < n; ++i)
    {
        dist[i] = 1e9;
        prevPoints[i] = i;
    }

    dist[s] = 0;
    int cycleStart = -1;
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            if (dist[i] == 1e9) continue;
            for (int j = 0; j < vEdge[i].size(); ++j)
            {
                int nextPoint = vEdge[i][j].first;
                int nextCost = dist[i] + vEdge[i][j].second;
                if (dist[nextPoint] > nextCost)
                {
                    if (k == n - 1)
                    {
                        cycleStart = nextPoint;
                    }

                    dist[nextPoint] = nextCost;
                    prevPoints[nextPoint] = i;
                }
            }
        }
    }

    if (cycleStart == -1)
    {
        cout << "PATH\n";
        for (int i = 0; i < n; ++i)
            cout << dist[i] << " ";
    }
    else
    {
        cout << "CYCLE\n";

        for (int i = 0; i < n; ++i) 
            cycleStart = prevPoints[cycleStart];

        vector<int> vCyclePoints;
        for (int i = cycleStart; ; i = prevPoints[i]) {
            vCyclePoints.push_back(i);
            if (i == cycleStart && vCyclePoints.size() > 1) break;
        }

        cout << vCyclePoints.size() - 1 << "\n";
        for (auto it = vCyclePoints.rbegin(); it != vCyclePoints.rend(); ++it) {
            cout << *it << " ";
        }
    }
}