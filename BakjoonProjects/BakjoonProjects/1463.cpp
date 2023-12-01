#include <iostream>
#include <array>
#include <algorithm>
#include <memory.h>
using namespace std;
array<int, 100'0001> dp;
int main()
{
    int n;
    cin >> n;

    dp.fill(0x7FFFFFFF);

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; ++i)
    {
        if (i % 3 == 0) dp[i] = min(dp[i], dp[static_cast<int>(i / 3)] + 1);
        if (i % 2 == 0) dp[i] = min(dp[i], dp[static_cast<int>(i / 2)] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    cout << dp[n];
}