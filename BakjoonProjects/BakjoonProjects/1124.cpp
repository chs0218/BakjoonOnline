#include <iostream>
#include <memory.h>
using namespace std;
bool bPrime[100001];
int A, B;
void setPrime()
{
    memset(bPrime, true, sizeof(bPrime));

    bPrime[0] = false;
    bPrime[1] = false;

    for (int i = 2; i <= 100000; ++i)
    {
        if (!bPrime[i]) continue;

        for (int j = i + i; j <= 100000; j += i)
            bPrime[j] = false;
    }
}
int nUnderPrime(int n)
{
    if (n == 1) return 0;
    if (bPrime[n]) return 1;

    for (int i = 2; i <= n; ++i)
    {
        if (bPrime[i] && (n % i == 0)) {
            return nUnderPrime(n / i) + 1;
        }
    }
}
int main()
{
    setPrime();

    cin >> A >> B;

    int ans = 0;
    for (int i = A; i <= B; ++i)
    {
        int ret = nUnderPrime(i);
        if (bPrime[ret]) ++ans;
    }
    cout << ans;
}