#include <iostream>
using namespace std;
/*
다이나믹 프로그래밍
*/
int dp[500][501];
int main()
{
    int nSize = 0;
    cin >> nSize;

    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
            cin >> dp[i][j];
    }

    int ans = 0;
    for (int i = 0; i < nSize; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            if (j == 0) dp[i][j] = dp[i][j] + dp[i - 1][j];
            else if (j == i) dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
            else {
                dp[i][j] = max(dp[i][j] + dp[i - 1][j],
                    dp[i][j] + dp[i - 1][j - 1]);
            }

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
}