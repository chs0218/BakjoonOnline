#include <iostream>
#include <math.h>
using namespace std;

// 1, 3, 2
// 11

int ProcessZ(int nFindX, int nFindY, int nBoardSize) {
    if (nBoardSize == 0)
        return 0;

    int nPow = pow(2, nBoardSize - 1);
    if (nFindX < nPow)
    {
        if (nFindY < nPow)
        {
            // 왼쪽 위
            return ProcessZ(nFindX, nFindY, nBoardSize - 1);
        }
        else
        {
            // 왼쪽 아래
            return 2 * nPow * nPow +
                ProcessZ(nFindX, nFindY - nPow, nBoardSize - 1);
        }
    }
    else
    {
        if (nFindY < nPow)
        {
            // 오른쪽 위
            return nPow * nPow +
                ProcessZ(nFindX - nPow, nFindY, nBoardSize - 1);
        }
        else
        {
            // 오른쪽 아래
            return 3 * nPow * nPow +
                ProcessZ(nFindX - nPow, nFindY - nPow, nBoardSize - 1);
        }
    }
}

int main()
{
    int n, x, y;
    cin >> n >> y >> x;

    int ans = ProcessZ(x, y, n);
    cout << ans;
}