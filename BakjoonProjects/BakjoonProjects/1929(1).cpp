#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nMin, nMax;
    cin >> nMin >> nMax;

    for (int i = nMin; i <= nMax; ++i)
    {
        if (i == 1) continue;
        bool bChk = true;
        for (int j = 2; j <= static_cast<int>(sqrt(i)); ++j)
        {
            if (i % j == 0)
            {
                bChk = false;
                break;
            }
        }

        if (bChk) cout << i << "\n";
    }
}