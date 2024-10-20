#include <iostream>
using namespace std;
/*
다이나믹 프로그래밍
*/
int arr[1001];
int dp[1001];
int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
        cin >> arr[i];

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        dp[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }
    cout << ans;
}