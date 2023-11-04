#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nNum;
    cin >> nNum;

    vector<int> vNums(nNum);
    vector<int> vCounts(8001);
    int nSum = 0;
    int nMin = 4000, nMax = -4000;
    for (int i = 0; i < nNum; ++i)
    {
        cin >> vNums[i];

        nSum += vNums[i];
        ++vCounts[vNums[i] + 4000];
        nMin = min(nMin, vNums[i]);
        nMax = max(nMax, vNums[i]);
    }

    sort(vNums.begin(), vNums.end());

    bool bChangeValue = true;;
    int nMaxFrequency = 0;
    int nMaxFrequencyNum = nMin + 4000;

    for (int i = nMin + 4000; i <= nMax + 4000; ++i)
    {
        if (nMaxFrequency < vCounts[i])
        {
            bChangeValue = true;
            nMaxFrequency = vCounts[i];
            nMaxFrequencyNum = i;
        }

        else if(bChangeValue && nMaxFrequency == vCounts[i])
        {
            bChangeValue = false;
            nMaxFrequencyNum = i;
        }
    }

    float fAverage = static_cast<float>(nSum) / static_cast<float>(nNum);
    cout << floor(fAverage + 0.5f) << "\n";
    cout << vNums[nNum / 2] << "\n";
    cout << nMaxFrequencyNum - 4000 << "\n";
    cout << nMax - nMin << "\n";

}