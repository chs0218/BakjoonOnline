#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nTree, nGoal;
    cin >> nTree >> nGoal;

    vector<int> vHeight(nTree);
    for (int i = 0; i < nTree; ++i)
        cin >> vHeight[i];

    sort(vHeight.begin(), vHeight.end());

    int nMin = 0;
    int nMax = *(vHeight.end() - 1);

    while (nMin + 1 < nMax) {
        long long nSum = 0;
        int nMiddle = (nMin + nMax) / 2;

        for (auto it = vHeight.rbegin(); it < vHeight.rend(); ++it)
        {
            int nHeight = *it;
            if (nHeight <= nMiddle) break;
            nSum += (nHeight - nMiddle);
        }

        if (nGoal <= nSum) nMin = nMiddle;
        else nMax = nMiddle;
    }

    cout << nMin;
}