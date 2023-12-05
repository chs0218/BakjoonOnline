#include <iostream>
#include <math.h>
using namespace std;
int nBlue = 0;
int nWhite = 0;
int nColor[128][128];
void CalNum(int nStartX, int nStartY, int nSize)
{
    bool bWhite = true, bBlue = true;
    int nSearchSize = pow(2, nSize);
    if (nColor[nStartY][nStartX] == 1)
    {
        bWhite = false;
        for (int i = 0; i < nSearchSize; ++i)
        {
            for (int j = 0; j < nSearchSize; ++j)
            {
                int nX = nStartX + j;
                int nY = nStartY + i;
                if (nColor[nY][nX] == 0)
                {
                    bBlue = false;
                    break;
                }
            }
        }
    }
    else
    {
        bBlue = false;
        for (int i = 0; i < nSearchSize; ++i)
        {
            for (int j = 0; j < nSearchSize; ++j)
            {
                int nX = nStartX + j;
                int nY = nStartY + i;
                if (nColor[nY][nX] == 1)
                {
                    bWhite = false;
                    break;
                }
            }
        }
    }

    if (bBlue || bWhite)
    {
        if (bBlue) ++nBlue;
        else ++nWhite;
    }
    else
    {
        CalNum(nStartX, nStartY, nSize - 1);
        CalNum(nStartX + nSearchSize / 2, nStartY, nSize - 1);
        CalNum(nStartX, nStartY + nSearchSize / 2, nSize - 1);
        CalNum(nStartX + nSearchSize / 2,
            nStartY + nSearchSize / 2,
            nSize - 1);
    }
}
int main()
{
    int nLength;
    cin >> nLength;
    for (int i = 0; i < nLength; ++i)
    {
        for (int j = 0; j < nLength; ++j)
            cin >> nColor[i][j];
    }

    int nSize = -1;
    while (nLength) {
        ++nSize;
        nLength = nLength >> 1;
    }

    CalNum(0, 0, nSize);
    cout << nWhite << "\n";
    cout << nBlue << "\n";
}