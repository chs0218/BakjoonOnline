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
    int nLoc, nCost;
};
vector<Edge> vGraph[1001];
bool operator<(Edge lhs, Edge rhs) {
    return lhs.nCost > rhs.nCost;
}
void dijkstra(int nStartPoint, int nEndPoint, int nCity)
{
    vector<int> ans(nCity + 1);

    for (int i = 0; i < ans.size(); ++i)
        ans[i] = 1e9;

    priority_queue<Edge> qEdge;
    qEdge.push(Edge{ nStartPoint, 0 });
    ans[nStartPoint] = 0;

    while (!qEdge.empty()) {
        int cur = qEdge.top().nLoc;
        int cost = qEdge.top().nCost;
        qEdge.pop();
        if (ans[cur] < cost)
            continue;
        for (int i = 0; i < vGraph[cur].size(); ++i)
        {
            int nextPoint = vGraph[cur][i].nLoc;
            int nextCost = vGraph[cur][i].nCost + cost;

            if (ans[nextPoint] > nextCost) {
                ans[nextPoint] = nextCost;
                qEdge.push(Edge{ nextPoint, nextCost });
            }
        }
    }

    cout << ans[nEndPoint];
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nCity;
    cin >> nCity;

    int nBus;
    cin >> nBus;

    int nStartPoint, nEndPoint, nCost;
    for (int i = 0; i < nBus; ++i)
    {
        cin >> nStartPoint >> nEndPoint >> nCost;
        vGraph[nStartPoint].push_back(Edge{ nEndPoint, nCost });
    }

    cin >> nStartPoint >> nEndPoint;
    dijkstra(nStartPoint, nEndPoint, nCity);
}