#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;
int N, M, V;
vector<int> Edge[1001];
bool bVisited[1001];
void DFS(int n)
{
    bVisited[n] = true;
    cout << n << " ";

    for (int i = 0; i < Edge[n].size(); ++i)
    {
        int Next = Edge[n][i];

        if (!bVisited[Next])
            DFS(Next);
    }
}

void BFS(int n)
{
    queue<int> Points;
    bVisited[n] = true;
    Points.push(n);

    while (!Points.empty())
    {
        int Cur = Points.front();
        Points.pop();

        cout << Cur << " ";

        for (int i = 0; i < Edge[Cur].size(); ++i)
        {
            int Next = Edge[Cur][i];

            if (!bVisited[Next])
            {
                bVisited[Next] = true;
                Points.push(Next);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i)
    {
        int Start, End;
        cin >> Start >> End;
        Edge[Start].push_back(End);
        Edge[End].push_back(Start);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(Edge[i].begin(), Edge[i].end());
    }


    memset(bVisited, false, sizeof(bVisited));
    DFS(V);

    cout << "\n";

    memset(bVisited, false, sizeof(bVisited));
    BFS(V);
}