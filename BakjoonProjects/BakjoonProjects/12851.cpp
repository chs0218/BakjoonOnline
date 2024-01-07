#include <iostream>
#include <queue>
using namespace std;
bool bVisited[100001];
int main()
{
    int N, K;
    cin >> N >> K;

    int ans = 1e9;
    int numAns = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bVisited[N] = true;
    pq.push({ 0, N });

    while (!pq.empty()) {
        int t = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        bVisited[cur] = true;

        if (t > ans) break;
        if (cur == K) {
            ++numAns;
            ans = t;
        }

        if (cur + 1 <= 100000 && !bVisited[cur + 1]) pq.push({ t + 1, cur + 1 });
        if (cur - 1 >= 0 && !bVisited[cur - 1]) pq.push({ t + 1, cur - 1 });
        if (cur * 2 <= 100000 && !bVisited[cur * 2]) pq.push({ t + 1, cur * 2 });
    }

    cout << ans << "\n";
    cout << numAns;
}