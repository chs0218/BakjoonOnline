#include <iostream>
#include <memory.h>
using namespace std;
char nBoard[50][50];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nWidth, nHeight;
    cin >> nHeight >> nWidth;

    memset(nBoard, ' ', sizeof(nBoard));

    for (int i = 0; i < nHeight; ++i)
    {
        for (int j = 0; j < nWidth; ++j)
            cin >> nBoard[i][j];
    }

    int nWidthCheck = nWidth - 8;
    int nHeightCheck = nHeight - 8;
    int nAns = 64;
    for (int i = 0; i <= nHeightCheck; ++i)
    {
        for (int j = 0; j <= nWidthCheck; ++j)
        {
            int nLTWhiteCount = 0;
            int nLTBlackCount = 0;

            // 최소값 세기
            for (int k = 0; k < 8; ++k)
            {
                for (int l = 0; l < 8; ++l)
                {
                    if ((k + l) % 2 == 0)
                    {
                        if (nBoard[i + k][j + l] == 'W')
                            ++nLTBlackCount;
                        else
                            ++nLTWhiteCount;
                    }
                    else
                    {
                        if (nBoard[i + k][j + l] == 'W')
                            ++nLTWhiteCount;
                        else
                            ++nLTBlackCount;
                    }
                }
            }

            int nMinCount = min(nLTWhiteCount, nLTBlackCount);
            nAns = min(nMinCount, nAns);
        }
    }

    cout << nAns;
}