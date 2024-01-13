#include <iostream>
#include <memory.h>
using namespace std;
bool prime[4000001];
void Eratos(int n)
{
    if (n <= 1) return;

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}
int main()
{
    int N;
    cin >> N;

    Eratos(N);

    int lhs = 2, rhs = 2, sum = 2;
    int ans = 0;
    while (1)
    {
        if (sum == N) ++ans;
        if (sum > N) {
            sum -= lhs;
            for (int i = lhs + 1; i <= N; ++i)
                if (prime[i]) {
                    lhs = i;
                    break;
                }
        }
        else {
            int prev = rhs;
            for (int i = rhs + 1; i <= N; ++i)
            {
                if (prime[i]) {
                    sum += i;
                    rhs = i;
                    break;
                }
            }
            if (prev == rhs) break;
        }
    }
    cout << ans;
}