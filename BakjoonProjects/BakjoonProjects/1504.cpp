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
bool operator<(Edge lhs, Edge rhs)
{
    return lhs.w > rhs.w;
}
vector<Edge> vEdge[801];
int N, E;
vector<long long> dijkstra(int n)
{
    vector<long long> ans(N + 1);

    for (int i = 0; i < ans.size(); ++i)
        ans[i] = 1e9;

    priority_queue<Edge> pq;
    pq.push(Edge{ n, 0 });
    ans[n] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().v;
        int cost = pq.top().w;
        pq.pop();

        if (ans[cur] < cost) continue;

        for (int i = 0; i < vEdge[cur].size(); ++i)
        {
            int nextNode = vEdge[cur][i].v;
            int nextCost = vEdge[cur][i].w + cost;
            if (ans[nextNode] > nextCost) {
                ans[nextNode] = nextCost;
                pq.push(Edge{ nextNode, nextCost });
            }
        }
    }

    return ans;
}
int main()
{
    cin >> N >> E;

    for (int i = 0; i < E; ++i)
    {
        int s, e, t;
        cin >> s >> e >> t;
        vEdge[s].push_back(Edge{ e, t });
        vEdge[e].push_back(Edge{ s, t });
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<long long> vDistStart = dijkstra(1);
    vector<long long> vDistV1 = dijkstra(v1);
    vector<long long> vDistV2 = dijkstra(v2);

    long long ans = 1e9;
    ans = min(ans, vDistStart[v1] + vDistV1[v2] + vDistV2[N]);
    ans = min(ans, vDistStart[v2] + vDistV2[v1] + vDistV1[N]);

    if (ans == 1e9) cout << "-1";
    else cout << ans;
}