#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
bool bChk[100'0001];
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nMin, nMax;
    cin >> nMin >> nMax;

    for (int i = 2; i <= nMax; ++i)
    {
        if (!bChk[i])
        {
            if (nMin <= i) cout << i << "\n";

            int n = i;
            while (n <= nMax) {
                bChk[n] = true;
                n += i;
            }
        }
    }
}