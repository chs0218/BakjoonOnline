#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
    int v, w;
};
bool operator<(Edge lhs, Edge rhs)
{
    return lhs.w > rhs.w;
}
vector<Edge> vEdge[10001];
int d[1001][1001];
int N, M, X;
void dijkstra(int n)
{
    for (int i = 1; i <= N; ++i)
    {
        if (n == i) d[n][i] = 0;
        else d[n][i] = 1e9;
    }
    priority_queue<Edge> qEdge;
    qEdge.push(Edge{ n, 0 });

    while (!qEdge.empty())
    {
        int cur = qEdge.top().v;
        int cost = qEdge.top().w;
        qEdge.pop();

        if (d[n][cur] < cost)
            continue;

        for (int i = 0; i < vEdge[cur].size(); ++i)
        {
            int nextNode = vEdge[cur][i].v;
            int nextCost = vEdge[cur][i].w + cost;
            if (d[n][nextNode] > nextCost)
            {
                d[n][nextNode] = nextCost;
                qEdge.push(Edge{ nextNode, nextCost });
            }
        }
    }
}
int main()
{
    cin >> N >> M >> X;

    for (int i = 0; i < M; ++i)
    {
        int lhs, rhs, w;
        cin >> lhs >> rhs >> w;
        vEdge[lhs].push_back(Edge{ rhs, w });
    }

    for (int i = 1; i <= N; ++i)
        dijkstra(i);

    int ans = 0;
    for (int i = 1; i <= N; ++i)
        ans = max(ans, d[i][X] + d[X][i]);
    cout << ans;
}