#include <iostream>
#include <vector>
#include <queue>
#include <memory>
using namespace std;
bool bVisited[101];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nUsers, nRelations;
    cin >> nUsers >> nRelations;

    vector<vector<int>> vNodes(nUsers + 1);

    for (int i = 0; i < nRelations; ++i)
    {
        int lhs, rhs;
        cin >> lhs >> rhs;

        vNodes[lhs].push_back(rhs);
        vNodes[rhs].push_back(lhs);
    }

    int nAns = -1;
    int nKevinBacon = 1e10;

    for (int i = 1; i <= nUsers; ++i)
    {
        int n = 0;
        for (int j = 1; j <= nUsers; ++j)
        {
            if (i == j) continue;
            memset(bVisited, false, sizeof(bVisited));
            queue<pair<int, int>> qNodes;

            qNodes.push(make_pair(i, 0));
            bVisited[i] = true;

            while (!qNodes.empty()) {
                auto cur = qNodes.front();
                qNodes.pop();

                if (cur.first == j) {
                    n += cur.second;
                    break;
                }

                for (auto node : vNodes[cur.first]) {
                    if (!bVisited[node]) {
                        bVisited[node] = true;
                        qNodes.push(make_pair(node, cur.second + 1));
                    }
                }
            }
        }

        if (nKevinBacon > n) {
            nAns = i;
            nKevinBacon = n;
        }
    }

    cout << nAns;
}