#include <iostream>
#include <queue>
using namespace std;
/*
그래프 이론
그리디 알고리즘
그래프 탐색
너비 우선 탐색
*/
int main()
{
    long long A, B;
    cin >> A >> B;

    queue<pair<long long, long long>> qNum;
    qNum.push(make_pair(A, 0));

    long long ans = -1;
    while (!qNum.empty())
    {
        long long cur = qNum.front().first;
        long long ret = qNum.front().second;
        qNum.pop();

        if (cur == B) {
            ans = ret + 1;
            break;
        }

        long long next = cur * 10 + 1;
        if (next <= B) qNum.push(make_pair(next, ret + 1));
        next = cur * 2; 
        if (next <= B) qNum.push(make_pair(next, ret + 1));
    }

    cout << ans;
}