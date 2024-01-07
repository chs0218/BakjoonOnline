#include <iostream>
#include <math.h>
#include <numeric>
using namespace std;
constexpr long long Mod = 1000000007;
long long myPow(long long a, long long b)
{
    if (b == 1) return a;
    if (b % 2 == 1) return a * myPow(a, b - 1) % Mod;
    long long tmp = myPow(a, b / 2);
    return (tmp * tmp) % Mod;
}
int main()
{
    int M;
    cin >> M;

    long long ans = 0;
    for (int i = 0; i < M; ++i)
    {
        long long N, S;
        cin >> N >> S;

        long long v = gcd(N, S);
        N /= v;
        S /= v;

        long long ret = S * myPow(N, Mod - 2) % Mod;
        ans += ret;
        ans %= Mod;
    }
    cout << ans;
}