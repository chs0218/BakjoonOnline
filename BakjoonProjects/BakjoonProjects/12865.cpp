#include <iostream>
#include <vector>
using namespace std;
struct Object {
    int weight;
    int value;
};
int dp[101][100001];
int main()
{
    int nObject, nMaxWeight;
    cin >> nObject >> nMaxWeight;

    vector<Object> vObject(nObject + 1);

    for (int i = 1; i <= nObject; ++i)
        cin >> vObject[i].weight >> vObject[i].value;

    for (int i = 1; i <= nObject; ++i)
    {
        for (int j = 1; j <= nMaxWeight; ++j)
        {
            if (vObject[i].weight <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vObject[i].weight] + vObject[i].value);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[nObject][nMaxWeight];
}