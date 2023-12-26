#include <iostream>
using namespace std;
int cost[1000][3];
int dp[1000][3];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nHouse;
    cin >> nHouse;

    for (int i = 0; i < nHouse; ++i)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 1; i < nHouse; ++i)
    {
        dp[i][0] = min(dp[i - 1][1] + cost[i][0], dp[i - 1][2] + cost[i][0]);
        dp[i][1] = min(dp[i - 1][0] + cost[i][1], dp[i - 1][2] + cost[i][1]);
        dp[i][2] = min(dp[i - 1][0] + cost[i][2], dp[i - 1][1] + cost[i][2]);
    }

    int ans = dp[nHouse - 1][0];
    ans = min(ans, dp[nHouse - 1][1]);
    ans = min(ans, dp[nHouse - 1][2]);
    cout << ans;
}