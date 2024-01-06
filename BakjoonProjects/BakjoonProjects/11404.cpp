#include <iostream>
#include <vector>
using namespace std;
int dp[101][101];
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = 1e9;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(dp[a][b] > c) dp[a][b] = c;
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dp[i][j] == 1e9) cout << "0 ";
            else cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}