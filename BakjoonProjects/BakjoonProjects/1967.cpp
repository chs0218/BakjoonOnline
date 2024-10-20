#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;
/*
그래프 이론
그래프 탐색
트리
깊이 우선 탐색
*/
struct Node {
    vector<pair<int, int>> vEdge;
};
Node arrNode[10001];
bool bVisited[10001];
int nNode = 0;
int maxNode = 0, maxDist = 0;
void bfs(int n)
{
    memset(bVisited, false, sizeof(bVisited));

    queue<pair<int, int>> qValue;
    qValue.push(make_pair(n, 0));
    bVisited[n] = true;

    while (!qValue.empty()) {
        int dist = qValue.front().second;
        int node = qValue.front().first;
        qValue.pop();

        if (maxDist < dist) {
            maxDist = dist;
            maxNode = node;
        }

        for (int i = 0; i < arrNode[node].vEdge.size(); ++i)
        {
            int nextNode = arrNode[node].vEdge[i].first;
            int nextDist = arrNode[node].vEdge[i].second + dist;

            if (!bVisited[nextNode]) {
                bVisited[nextNode] = true;
                qValue.push(make_pair(nextNode, nextDist));
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> nNode;
    for (int i = 0; i < nNode - 1; ++i)
    {
        int root, cn, w;
        cin >> root >> cn >> w;

        arrNode[root].vEdge.push_back(make_pair(cn, w));
        arrNode[cn].vEdge.push_back(make_pair(root, w));
    }

    bfs(1);
    maxDist = 0;
    bfs(maxNode);
    cout << maxDist;
}