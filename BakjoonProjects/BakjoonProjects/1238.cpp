#include <iostream>
using namespace std;
/*
그래프 이론
최단 경로
데이크스트라
*/
int dp[1001][1001];
int N, M, X;
int main()
{
    cin >> N >> M >> X;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j){
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = 1e9;
        }

    for (int i = 0; i < M; ++i)
    {
        int lhs, rhs, w;
        cin >> lhs >> rhs >> w;
        dp[lhs][rhs] = w;
    }

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    int ans = 0;
    for (int i = 1; i <= N; ++i)
        ans = max(ans, dp[i][X] + dp[X][i]);
    cout << ans;
}