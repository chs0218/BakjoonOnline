#include <iostream>
#include <queue>
using namespace std;
struct Info {
    int v, w;
};
bool operator<(Info lhs, Info rhs)
{
    if (lhs.w == rhs.w) return lhs.v > rhs.v;
    return lhs.w > rhs.w;
}
bool bVisited[100001];
int N, K;
int main()
{
    cin >> N >> K;

    priority_queue<Info> pq;
    bVisited[N] = true;
    pq.push(Info{ N, 0 });

    int ans = 0;
    while (!pq.empty()) {
        int cur = pq.top().v;
        int t = pq.top().w;

        cout << cur << " " << t << endl;
        pq.pop();

        if (cur == K) {
            ans = t;
            break;
        }

        if (cur * 2 <= 100000 && !bVisited[cur * 2]) {
            bVisited[cur * 2] = true;
            pq.push(Info{ cur * 2, t });
        }

        if (cur + 1 <= 100000 && !bVisited[cur + 1]) {
            bVisited[cur + 1] = true;
            pq.push(Info{ cur + 1, t + 1 });
        }

        if (cur - 1 >= 0 && !bVisited[cur - 1]) {
            bVisited[cur - 1] = true;
            pq.push(Info{ cur - 1, t + 1 });
        }
    }
    cout << ans;
}