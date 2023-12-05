#include <iostream>
#include <vector>
using namespace std;
int dp[301];
int main()
{
    int nStair;
    cin >> nStair;

    vector<int> vScore(nStair);
    for (int i = 0; i < nStair; ++i)
        cin >> vScore[i];

    if (nStair < 3) {
        if (nStair == 1) cout << vScore[0];
        if (nStair == 2) cout << vScore[0] + vScore[1];
        return 0;
    }

    dp[0] = 0;
    dp[1] = vScore[0];
    dp[2] = vScore[0] + vScore[1];
    for (int i = 3; i <= nStair; ++i) {
        dp[i] = max(dp[i - 2] + vScore[i - 1], dp[i - 3] + vScore[i - 2] + vScore[i - 1]);
    }

    cout << dp[nStair];
}