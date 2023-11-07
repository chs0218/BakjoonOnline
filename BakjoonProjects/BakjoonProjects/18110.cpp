#include <iostream>
#include <math.h>
#include <array>
using namespace std;
array<int, 31> arrLevels;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nComment;
    cin >> nComment;

    if (nComment == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < nComment; ++i)
    {
        int n;
        cin >> n;
        ++arrLevels[n];
    }

    int nTotalDel = floor((static_cast<float>(nComment) * 0.15f + 0.5f));

    int nDel = nTotalDel;
    for (int i = 0; i < 31; ++i)
    {
        if (nDel == 0)
            break;

        if (nDel - arrLevels[i] >= 0)
        {
            nDel -= arrLevels[i];
            arrLevels[i] = 0;
        }
        else
        {
            arrLevels[i] -= nDel;
            break;
        }
    }

    nDel = nTotalDel;
    for (int i = 30; i >= 0; --i)
    {
        if (nDel == 0)
            break;

        if (nDel - arrLevels[i] >= 0)
        {
            nDel -= arrLevels[i];
            arrLevels[i] = 0;

            if (nDel == 0)
                break;
        }
        else
        {
            arrLevels[i] -= nDel;
            break;
        }
    }

    int nSum = 0;
    for (int i = 1; i < 31; ++i)
        nSum += i * arrLevels[i];
    
    float fAns = static_cast<float>(nSum) / static_cast<float>(nComment - nTotalDel * 2) + 0.5f;
    fAns = floor(fAns);
    cout << fAns;
}