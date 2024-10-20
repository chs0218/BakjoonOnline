#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
/*
그래프 이론
최단 경로
데이크스트라
플로이드?워셜
*/
int item[101];
vector<pair<int, int>> vEdge[101];
int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; ++i)
        cin >> item[i];

    for (int i = 0; i < r; ++i)
    {
        int a, b, l;
        cin >> a >> b >> l;
        vEdge[a].push_back({ b, l });
        vEdge[b].push_back({ a, l });
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        vector<int> dist(n + 1, 1e9);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[i] = 0;
        pq.push({ 0, i });

        while (!pq.empty())
        {
            int curNode = pq.top().second;
            int curDist = pq.top().first;
            pq.pop();

            if (dist[curNode] < curDist) continue;

            for (int j = 0; j < vEdge[curNode].size(); ++j)
            {
                int nextNode = vEdge[curNode][j].first;
                int nextDist = vEdge[curNode][j].second + curDist;

                if (dist[nextNode] > nextDist)
                {
                    dist[nextNode] = nextDist;
                    pq.push({ nextDist, nextNode });
                }
            }
        }

        int ret = 0;
        for (int j = 1; j <= n; ++j)
            if (dist[j] <= m) ret += item[j];
        ans = max(ans, ret);
    }
    cout << ans;
}