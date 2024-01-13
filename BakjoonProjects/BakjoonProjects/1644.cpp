#include <iostream>
#include <vector>
using namespace std;
vector<int> Eratos(int n)
{
    vector<bool> bPrime(n + 1, true);
    vector<int> vPrime;

    bPrime[0] = false;
    bPrime[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (bPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                bPrime[j] = false;
        }
    }

    for (int i = 2; i <= n; ++i)
        if (bPrime[i]) vPrime.push_back(i);

    return vPrime;
}
int main()
{
    int N;
    cin >> N;

    if (N <= 1) {
        cout << "0";
        return 0;
    }

    vector<int> vPrime = Eratos(N);

    int lhs = 0, rhs = 0, sum = vPrime[0];
    int ans = 0;

    while (1)
    {
        if (sum == N) ++ans;
        if (sum > N) sum -= vPrime[lhs++];
        else if (rhs == vPrime.size() - 1) break;
        else sum += vPrime[++rhs];
    }
    cout << ans;
}