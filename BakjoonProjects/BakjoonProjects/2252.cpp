#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
그래프 이론
위상 정렬
방향 비순환 그래프
*/
int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> ans;
    vector<int> vTopology(N);
    vector<vector<int>> vCompare(N);

    for (int i = 0; i < M; ++i)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;
        vCompare[lhs - 1].push_back(rhs - 1);
        vTopology[rhs - 1]++;
    }

    queue<int> q;

    for (int i = 0; i < N; ++i)
    {
        if (vTopology[i] == 0)
            q.push(i);
    }

    for (int i = 0; i < N; ++i)
    {
        if (q.empty()) break;
        int cur = q.front();
        q.pop();

        ans.push_back(cur);

        for (int j = 0; j < vCompare[cur].size(); ++j)
        {
            int next = vCompare[cur][j];
            if (--vTopology[next] == 0)
                q.push(next);
        }
    }

    for (const int& n : ans)
        cout << n + 1 << " ";
}