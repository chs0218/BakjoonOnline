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

vector<Edge> vEdge[300001];
int N, M, K, X;

void dijkstra()
{
    vector<int> ans(N + 1);
    for (int i = 0; i < ans.size(); ++i)
        ans[i] = 1e9;

    priority_queue<Edge> qEdge;
    ans[X] = 0;
    qEdge.push(Edge{ X, 0 });

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

    int nAns = 0;
    for (int i = 1; i < ans.size(); ++i)
    {
        if (ans[i] == K) {
            cout << i << "\n";
            ++nAns;
        }
    }

    if (nAns == 0)
        cout << "-1";
}

int main()
{
    cin >> N >> M >> K >> X;
    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        vEdge[A].push_back(Edge{ B, 1 });
    }
    
    dijkstra();
}