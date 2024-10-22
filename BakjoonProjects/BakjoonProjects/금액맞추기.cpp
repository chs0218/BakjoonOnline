#include <iostream>
using namespace std;
/*
���̳��� ���α׷���
*/
int coins[50][10];
int dp[50][1001];   // n���� ����� ���� ���� ��, ���� k�� �Ǵ� ����� ��
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        int nCoin;
        cin >> nCoin;
        for (int j = 0; j < nCoin; ++j)
        {
            cin >> coins[i][j];
        }
    }

    // Initialize
    // ù��° ����� ��� �ִ� �������� �ʱ�ȭ
    
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = 1;
    }

    for (int i = 0; i < 10; ++i)
    {
        // ���� ������ 0�̸� Ž�� �Ϸ�
        if (coins[0][i] == 0) break;
        dp[0][coins[0][i]] += 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (coins[i][j] == 0) break;
            dp[i][coins[i][j]] += 1;
        }

        for (int j = 1; j <= 1000; ++j)
        {
            dp[i][j] += dp[i - 1][j];
            for (int k = 0; k < 10; ++k)
            {
                if (coins[i][k] == 0) break;
                if (dp[i - 1][j] > 0 && j + coins[i][k] <= 1000)
                {
                    dp[i][j + coins[i][k]] += dp[i - 1][j];
                }
            }
        }
    }

    cout << dp[n - 1][k] % 10007;
    return 0;
}