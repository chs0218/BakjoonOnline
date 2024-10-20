#include <iostream>
using namespace std;
/*
브루트포스 알고리즘
백트래킹
*/
int N;
int ans = 0;
int queenX[15];
bool bCheck(int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (queenX[i] == queenX[n] || abs(queenX[n] - queenX[i]) == n - i)
            return false;
    }
    return true;
}
void NQueen(int nq)
{
    if (nq == N) ++ans;
    else {
        for (int i = 0; i < N; ++i)
        {
            queenX[nq] = i;
            if (bCheck(nq))
                NQueen(nq + 1);
        }
    }
}
int main()
{
    cin >> N;
    NQueen(0);
    cout << ans;
}