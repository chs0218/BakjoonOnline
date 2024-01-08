#include <iostream>
#include <array>
using namespace std;
constexpr int MOD = 1000;
array<array<int, 5>, 5> rc;
int N;
long long B;
array<array<int, 5>, 5> myMul(array<array<int, 5>, 5> lhs, array<array<int, 5>, 5> rhs)
{
    array<array<int, 5>, 5> ret;
    ret[0].fill(0);
    ret[1].fill(0);
    ret[2].fill(0);
    ret[3].fill(0);
    ret[4].fill(0);

    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            for (int i = 0; i < N; ++i)
            {
                ret[r][c] += lhs[r][i] * rhs[i][c];
                ret[r][c] %= MOD;
            }
        }
    }
    return ret;
}
array<array<int, 5>, 5> myPow(long long n)
{
    if (n == 1) return rc;
    if (n == 2) return myMul(rc, rc);

    array<array<int, 5>, 5> ret;

    if (n % 2 == 0) {
        array<array<int, 5>, 5> tmp = myPow(n / 2);
        ret = myMul(tmp, tmp);
    }
    else {
        array<array<int, 5>, 5> tmp = myPow(n / 2);
        ret = myMul(myMul(tmp, tmp), rc);
    }
    
    return ret;
}
int main()
{
    cin >> N >> B;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> rc[i][j];

    array<array<int, 5>, 5> ans = myPow(B);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << ans[i][j] % MOD << " ";
        cout << "\n";
    }
}
