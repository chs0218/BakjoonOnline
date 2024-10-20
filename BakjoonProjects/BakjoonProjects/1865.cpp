#include <iostream>
#include <vector>
using namespace std;
/*
그래프 이론
최단 경로
벨만?포드
*/
struct Edge {
    int s, e, t;
};
bool BellManFord(int N, const vector<Edge>& edges)
{
    vector<int> dist(N + 1, 1e9);

    dist[1] = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            int s = edges[j].s;
            int e = edges[j].e;
            int t = edges[j].t;
            if (dist[e] > dist[s] + t) {
                dist[e] = dist[s] + t;
            }
        }
    }

    for (int i = 0; i < edges.size(); ++i) {
        int s = edges[i].s;
        int e = edges[i].e;
        int t = edges[i].t;
        if (dist[e] > dist[s] + t) {
            return true;
        }
    }

    return false;
}
int main()
{
    int TC;
    cin >> TC;

    for (int tc = 0; tc < TC; ++tc)
    {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> vEdge;

        for (int i = 0; i < M; ++i)
        {
            int S, E, T;
            cin >> S >> E >> T;
            vEdge.push_back(Edge{ S, E, T });
            vEdge.push_back(Edge{ E, S, T });
        }

        for (int i = 0; i < W; ++i)
        {
            int S, E, T;
            cin >> S >> E >> T;
            vEdge.push_back(Edge{ S, E, -T });
        }

        if (BellManFord(N, vEdge)) cout << "YES\n";
        else cout << "NO\n";
    }
}