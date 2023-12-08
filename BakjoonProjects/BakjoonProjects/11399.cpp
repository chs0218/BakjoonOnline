#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int nClient = 0;
    cin >> nClient;

    vector<int> vCost(nClient);
    for (int i = 0; i < nClient; ++i) {
        cin >> vCost[i];
    }

    sort(vCost.begin(), vCost.end());

    int ans = 0;
    for (int i = 0; i < nClient; ++i) {
        ans += vCost[i] * (nClient - i);
    }

    cout << ans;
}
