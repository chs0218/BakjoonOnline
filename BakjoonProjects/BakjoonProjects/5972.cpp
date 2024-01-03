#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
    int v, w;
};
bool operator<(Edge lhs, Edge rhs) {
    return lhs.w > rhs.w;
}
vector<Edge> vEdge[50001];
int N, M;
void dijkstra() {
    vector<int> ans(N + 1);
    for (int i = 0; i < N + 1; ++i)
        ans[i] = 1e9;

    priority_queue<Edge> qEdge;
    ans[1] = 0;
    qEdge.push(Edge{ 1, 0 });

    while (!qEdge.empty()) {
        int cur = qEdge.top().v;
        int cost = qEdge.top().w;
        qEdge.pop();

        if (ans[cur] < cost)
            continue;

        for (int i = 0; i < vEdge[cur].size(); ++i) {
            int nextPoint = vEdge[cur][i].v;
            int nextCost = vEdge[cur][i].w + cost;

            if (ans[nextPoint] > nextCost) {
                ans[nextPoint] = nextCost;
                qEdge.push(Edge{ nextPoint, nextCost });
            }
        }
    }

    cout << ans[N];
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int A_i, B_i, C_i;
        cin >> A_i >> B_i >> C_i;
        vEdge[A_i].push_back(Edge{ B_i, C_i });
        vEdge[B_i].push_back(Edge{ A_i, C_i });
    }

    dijkstra();
}