#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    deque<int> dq;

    for (int i = 1; i <= N; ++i)
        dq.push_back(i);

    int ans = 0;
    for (int i = 0; i < M; ++i)
    {
        int n;
        cin >> n;

        int opNum = 0;
        for (auto it = dq.begin(); it < dq.end(); ++it)
        {
            if (*it == n) break;
            ++opNum;
        }

        if (opNum < dq.size() - opNum) {
            ans += opNum;
            for (int j = 0; j < opNum; ++j) {
                int cur = dq.front();
                dq.pop_front();
                dq.push_back(cur);
            }
        }
        else {
            ans += dq.size() - opNum;
            for (int j = 0; j < dq.size() - opNum; ++j) {
                int cur = dq.back();
                dq.pop_back();
                dq.push_front(cur);
            }
        }

        dq.pop_front();
    }

    cout << ans;
}