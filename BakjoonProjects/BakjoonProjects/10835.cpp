#include <iostream>
using namespace std;
/*
다이나믹 프로그래밍
*/
int leftCard[2000];
int rightCard[2000];
int dp[2001][2001];
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> leftCard[i];
    for (int i = 0; i < n; ++i)
        cin >> rightCard[i];

    // Initialize
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = -1e9;

    dp[0][0] = 0;
    if (leftCard[0] > rightCard[0])
        dp[0][1] = rightCard[0];

    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 0;
        if (leftCard[0] > rightCard[i - 1] && dp[0][i - 1] != -1e9)
        {
            dp[0][i] = dp[0][i - 1] + rightCard[i - 1];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
            if (leftCard[i] > rightCard[j - 1] && dp[i][j - 1] != -1e9)
            {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + rightCard[j - 1]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans = max(ans, dp[n][i]);
        ans = max(ans, dp[i][n]);
    }
    cout << ans;
}