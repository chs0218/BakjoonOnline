#include <iostream>
#include <unordered_map>
using namespace std;
/*
수학
분할 정복을 이용한 거듭제곱
*/
constexpr long long MOD = 1000000007;
unordered_map<long long, long long> um;
long long Fibo(long long n)
{
    if (um[n]) return um[n];

    if (n % 2 == 0) um[n] = ((Fibo(n / 2) % MOD) * ((Fibo(n / 2 + 1) % MOD 
        + Fibo(n / 2 - 1) % MOD) % MOD)) % MOD;
    else um[n] = ((((Fibo((n + 1) / 2) % MOD) 
        * (Fibo((n + 1) / 2) % MOD)) % MOD) 
        + (((Fibo((n - 1) / 2) % MOD) * (Fibo((n - 1) / 2) % MOD)) % MOD)) % MOD;

    return um[n];
}
int main()
{
    long long n;
    cin >> n;

    um[0] = 0;
    um[1] = 1;
    um[2] = 1;

    cout << Fibo(n);
}