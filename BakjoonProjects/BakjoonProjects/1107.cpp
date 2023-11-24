#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;
bool nBtn[10];
int bMakable(int nTarget) {
    int nDigit = 0;

    if (nTarget == 0) {
        if (false == nBtn[0]) return -1;
        else return 1;
    }

    while (nTarget) {
        if (false == nBtn[nTarget % 10]) return -1;
        nTarget /= 10;
        ++nDigit;
    }

    return nDigit;
}

int main()
{
    int nChannel, nBkBtn, nAns;

    cin >> nChannel >> nBkBtn;

    memset(nBtn, true, sizeof(nBtn));
    for (int i = 0; i < nBkBtn; ++i)
    {
        int n;
        cin >> n;
        nBtn[n] = false;
    }

    nAns = abs(nChannel - 100);
    for (int i = nChannel; i >= 0; --i) {
        int ret = bMakable(i);
        if (ret != -1) {
            nAns = min(nAns, ret + nChannel - i);
            break;
        }
    }
    for (int i = nChannel; i <= 100'0000; ++i) {
        int ret = bMakable(i);
        if (ret != -1) {
            nAns = min(nAns, ret + i - nChannel);
            break;
        }
    }
    cout << nAns;
}