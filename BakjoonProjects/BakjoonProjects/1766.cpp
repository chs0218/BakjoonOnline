#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
�ڷ� ����
�׷��� �̷�
�켱���� ť
���� ����
���� ���ȯ �׷���
*/
int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> vCount(N + 1);
    vector<vector<int>> vEdge(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;

        ++vCount[rhs];
        vEdge[lhs].push_back(rhs);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; ++i)
        if (vCount[i] == 0) pq.push(i);

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        for (int i = 0; i < vEdge[cur].size(); ++i)
        {
            int next = vEdge[cur][i];
            if (--vCount[next] == 0)
                pq.push(next);
        }
    }
}