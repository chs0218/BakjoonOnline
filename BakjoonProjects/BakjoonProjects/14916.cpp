#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;

    for (int i = 6; i <= n; ++i)
    {
        if (dp[i - 2] != -1)
            dp[i] = dp[i - 2] + 1;

        if (dp[i - 5] != -1)
        {
            if(dp[i] != -1)
                dp[i] = dp[i - 5] + 1;
            else
                dp[i] = min(dp[i], dp[i - 5] + 1);
        }
    }
    cout << dp[n];
}