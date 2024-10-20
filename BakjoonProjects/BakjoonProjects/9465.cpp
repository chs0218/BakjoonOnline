#include <iostream>
#include <memory.h>
using namespace std;
/*
다이나믹 프로그래밍
*/
int dp[3][100001];
int score[3][100001];
int main()
{
    int nTestCase;
    cin >> nTestCase;

    for (int k = 0; k < nTestCase; ++k)
    {
        memset(dp, 0, sizeof(dp));
        int n;
        cin >> n;

        for (int i = 1; i <= 2; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> score[i][j];

        dp[1][1] = score[1][1];
        dp[2][1] = score[2][1];

        for (int i = 2; i <= n; ++i)
        {
            dp[1][i] = max(dp[2][i - 1] + score[1][i], dp[2][i - 2] + score[1][i]);
            dp[2][i] = max(dp[1][i - 1] + score[2][i], dp[1][i - 2] + score[2][i]);
        }

        int ans = max(dp[1][n], dp[2][n]);
        cout << ans << "\n";
    }
}