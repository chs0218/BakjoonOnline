#include <iostream>
#include <math.h>
using namespace std;
int dp[5'0001];
int main()
{
    int num;
    cin >> num;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= num; ++i)
    {
        dp[i] = 1e10;
        for (int j = 1; j <= static_cast<int>(sqrt(i)); ++j)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    cout << dp[num];
}