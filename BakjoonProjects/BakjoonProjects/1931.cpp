#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nConference;
    cin >> nConference;

    vector<pair<int, int>> vConference(nConference);

    for (int i = 0; i < nConference; ++i)
    {
        int nStartT, nEndT;
        cin >> nStartT >> nEndT;
        vConference[i].first = nStartT;
        vConference[i].second = nEndT;
    }

    sort(vConference.begin(), vConference.end(),
        [](const pair<int, int> lhs, const pair<int, int> rhs) {
            if (lhs.second == rhs.second)
                return lhs.first < rhs.first;
            return lhs.second < rhs.second;
        });

    int ans = 0;
    int endT = 0;

    for (const pair<int, int>& conf : vConference) {
        if (endT <= conf.first) {
            ++ans;
            endT = conf.second;
        }
    }

    cout << ans;
}