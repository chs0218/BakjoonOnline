#include <iostream>
#include <vector>
using namespace std;
int dp[100000][2];
int main()
{
    int N;
    cin >> N;

    vector<int> vNums(N);

    for (int i = 0; i < N; ++i)
        cin >> vNums[i];

    int ans = 1;
    for (int i = 0; i < N; ++i)
    {
        dp[i][0] = 1;
        dp[i][1] = 1;

        if (i == 0) continue;

        if (vNums[i] <= vNums[i - 1])
        {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        if (vNums[i] >= vNums[i - 1])
        {
            dp[i][1] = dp[i - 1][1] + 1;
        }
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
}