#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
다이나믹 프로그래밍
그래프 이론
위상 정렬
방향 비순환 그래프
*/
int cost[1001];
int ans[1001];
int nTopology[1001];
vector<int> vEdge[1001];
int main()
{
    int T;
    cin >> T;
    while (T) {
        int N, K;
        cin >> N >> K;
        for (int i = 1; i <= N; ++i)
        {
            cin >> cost[i];
            nTopology[i] = 0;
            ans[i] = cost[i];
            vEdge[i].clear();
        }

        for (int i = 1; i <= K; ++i)
        {
            int lhs, rhs;
            cin >> lhs >> rhs;
            vEdge[lhs].push_back(rhs);
            ++nTopology[rhs];
        }

        int goal;
        cin >> goal;

        queue<int> q;

        for (int i = 1; i <= N; ++i)
        {
            if (nTopology[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < vEdge[cur].size(); ++i)
            {
                int nextNode = vEdge[cur][i];
                int nextCost = cost[nextNode] + ans[cur];

                ans[nextNode] = max(ans[nextNode], nextCost);
                if (--nTopology[nextNode] == 0)
                    q.push(nextNode);
            }
        }

        cout << ans[goal] << "\n";
        --T;
    }
}