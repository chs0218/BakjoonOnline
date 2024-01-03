#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> vNode[100001];
int ans[100001];
void bfs(int n)
{
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    ans[1] = 1;

    while (!q.empty()) {
        int cur = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int i = 0; i < vNode[cur].size(); ++i) {
            int next = vNode[cur][i];
            if (ans[next] == 0) {
                ans[next] = cur;
                q.push(make_pair(next, cur));
            }
        }
    }
}
int main()
{
    int nNode;
    cin >> nNode;

    for (int i = 0; i < nNode - 1; ++i)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;

        vNode[lhs].push_back(rhs);
        vNode[rhs].push_back(lhs);
    }

    bfs(1);

    for (int i = 2; i <= nNode; ++i)
        cout << ans[i] << "\n";
}