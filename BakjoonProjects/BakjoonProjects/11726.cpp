#include <iostream>
using namespace std;
int dp[1001];
int main()
{
    // 1 -> 1
    // 2 -> 2
    // 3 -> 3
    // 4 -> 5
    // 5 -> 8
    // 6 -> 13
    // 7 -> 21
    // 8 -> 34
    // 9 -> 55

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 10007;
    }

    cout << dp[n];
}