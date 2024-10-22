#include <iostream>
using namespace std;
/*
���̳��� ���α׷���
*/
int dp[10][2001]; // n + 1���� �������, �������� m + 1�� �� ����� ��
const int MOD = 1000000007;
int main() {
    int n, m;
    cin >> n >> m;

    // initialize
    // 1���� ����� ���� ����� ��
    for (int i = 1; i <= m; ++i)
        dp[0][i] = 1;


    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 1; k <= j / 2; ++k)
            {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i)
        ans += dp[n - 1][i];
    cout << ans;
    return 0;
}