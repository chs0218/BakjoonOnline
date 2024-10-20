#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
그래프 이론
최단 경로
데이크스트라
*/
int n, m;
int S, E;
vector<pair<int, int>> vEdge[1001];
struct Info {
    vector<int> vCity;
    int v, w;
};
bool operator<(Info lhs, Info rhs)
{
    if (lhs.w == rhs.w) return lhs.v > rhs.v;
    else return lhs.w > rhs.w;
}
void dijkstra()
{
    vector<int> ans(n + 1, 1e9);
    vector<int> vAnsCity;
    ans[S] = 0;

    priority_queue<Info> pq;
    pq.push({ vector<int>{ S }, S, 0 });

    while (!pq.empty())
    {
        Info cur = pq.top();
        pq.pop();

        if (ans[cur.v] < cur.w) continue;

        for (int i = 0; i < vEdge[cur.v].size(); ++i)
        {
            int nextNode = vEdge[cur.v][i].first;
            int nextCost = vEdge[cur.v][i].second + cur.w;

            if (ans[nextNode] > nextCost)
            {
                ans[nextNode] = nextCost;

                vector<int> city = cur.vCity;
                city.push_back(nextNode);

                if (nextNode == E) 
                    vAnsCity = city;
                pq.push({ city, nextNode, nextCost });
            }
        }
    }

    cout << ans[E] << "\n";
    cout << vAnsCity.size() << "\n";
    for (const int& v : vAnsCity)
        cout << v << " ";
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int s, e, w;
        cin >> s >> e >> w;
        vEdge[s].push_back({ e, w });
    }

    cin >> S >> E;

    dijkstra();
}