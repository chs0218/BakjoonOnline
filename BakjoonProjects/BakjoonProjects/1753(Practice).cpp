#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
int V, E, K;
vector<pair<int, int>> Edge[20001];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> V >> E >> K;
    for (int i = 0; i < E; ++i)
    {
        int Start, End, Weight;
        cin >> Start >> End >> Weight;
        Edge[Start].push_back({ End, Weight });
    }

    vector<int> Ans(V + 1, 1e9);
    Ans[K] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Pq;
    Pq.push({ 0, K });

    while (!Pq.empty())
    {
        int Cur = Pq.top().second;
        int Cost = Pq.top().first;
        Pq.pop();

        if (Ans[Cur] < Cost) continue;

        for (int i = 0; i < Edge[Cur].size(); ++i)
        {
            int Next = Edge[Cur][i].first;
            int NextCost = Cost + Edge[Cur][i].second;

            if (Ans[Next] > NextCost)
            {
                Ans[Next] = NextCost;
                Pq.push({ NextCost, Next });
            }
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (Ans[i] == 1e9) cout << "INF\n";
        else cout << Ans[i] << "\n";
    }
}