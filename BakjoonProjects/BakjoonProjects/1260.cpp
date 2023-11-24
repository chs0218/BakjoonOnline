#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
bool bVisited[1001];
vector<set<int>> vNode;
vector<int> vDfs, vBfs;
int nStartPoint = 0;
void dfs(int n) {
    bVisited[n] = true;
    vDfs.push_back(n);
    for (int p : vNode[n]) {
        if (false == bVisited[p]) dfs(p);
    }
}
void bfs(int n) {
    queue<int> qPoint;
    qPoint.push(n);
    bVisited[n] = true;
    while (false == qPoint.empty()) {
        int p = qPoint.front();
        qPoint.pop();
        vBfs.push_back(p);
        for (int np : vNode[p]) {
            if (false == bVisited[np]) {
                bVisited[np] = true;
                qPoint.push(np);
            }
        }
    }
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);


    int nPoint, nNode;
    cin >> nPoint >> nNode >> nStartPoint;

    vNode.resize(nPoint + 1);

    for (int i = 0; i < nNode; ++i) {
        int rhs = 0, lhs = 0;
        cin >> rhs >> lhs;
        vNode[rhs].insert(lhs);
        vNode[lhs].insert(rhs);
    }
    dfs(nStartPoint);
    memset(bVisited, false, sizeof(bVisited));
    bfs(nStartPoint);

    for (int n : vDfs)
        cout << n << " ";
    cout << "\n";
    for (int n : vBfs)
        cout << n << " ";
}