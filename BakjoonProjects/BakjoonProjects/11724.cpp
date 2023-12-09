#include <iostream>
#include <queue>
using namespace std;
bool bNode[1001][1001];
bool bVisited[1001];
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nNode, nEdge;
    cin >> nNode >> nEdge;

    for (int i = 0; i < nEdge; ++i)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;
        bNode[lhs][rhs] = true;
        bNode[rhs][lhs] = true;
    }

    int ans = 0;
    for (int i = 1; i <= nNode; ++i)
    {
        if (bVisited[i]) continue;

        ans += 1;
        bVisited[i] = true;

        queue<int> qNode;
        qNode.push(i);

        while (!qNode.empty()) {
            int node = qNode.front();
            qNode.pop();

            for (int j = 1; j <= nNode; ++j)
            {
                if (!bNode[node][j] || bVisited[j]) continue;
                bVisited[j] = true;
                qNode.push(j);
            }
        }
    }

    cout << ans;
}