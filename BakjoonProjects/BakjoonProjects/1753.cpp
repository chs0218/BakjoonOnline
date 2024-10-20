#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
그래프 이론
최단 경로
데이크스트라
*/
struct Edge {
    int v, w;
};
bool operator<(Edge lhs, Edge rhs) {
    return lhs.w > rhs.w;
}
vector<Edge> vEdge[20001];
int V, E, K;
void dijkstra(int nStartPoint, int nVertex)
{
    vector<int> ans(nVertex + 1);
    for (int i = 0; i < ans.size(); ++i)
        ans[i] = 1e9;

    priority_queue<Edge> qEdge;
    ans[nStartPoint] = 0;
    qEdge.push(Edge{ nStartPoint, 0 });

    while (!qEdge.empty()) {
        int cur = qEdge.top().v;
        int cost = qEdge.top().w;
        qEdge.pop();

        if (ans[cur] < cost)
            continue;

        for (int i = 0; i < vEdge[cur].size(); ++i)
        {
            int nextPoint = vEdge[cur][i].v;
            int nextCost = vEdge[cur][i].w + cost;

            if (ans[nextPoint] > nextCost) {
                ans[nextPoint] = nextCost;
                qEdge.push(Edge{ nextPoint, nextCost });
            }
        }
    }

    for (int i = 1; i < ans.size(); ++i)
    {
        if (ans[i] == 1e9)
            cout << "INF\n";
        else
            cout << ans[i] << "\n";
    }
}
int main()
{
    cout.tie(NULL);
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> V >> E >> K;

    priority_queue<Edge> qEdge;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vEdge[u].push_back(Edge{ v, w });
    }

    dijkstra(K, V);
}