#include <iostream>
#include <vector>;
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nCoin, nGoal;
    cin >> nCoin >> nGoal;

    vector<int> vCoin(nCoin);
    for (int i = nCoin; i > 0; --i)
        cin >> vCoin[i - 1];

    int ans = 0;
    for (const int& n : vCoin) {
        while (nGoal >= n) {
            ++ans;
            nGoal -= n;
        }
    }

    cout << ans;
}