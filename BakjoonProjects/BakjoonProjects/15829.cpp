#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nLength;
    cin >> nLength;

    string str;
    cin >> str;

    long long nSum = 0;
    long long nMul = 1;
    long long nDivide = 1234567891;
    for (int i = 0; i < str.size(); ++i)
    {
        int n = (static_cast<int>(str[i]) - static_cast<int>('a') + 1);
        nSum += static_cast<long long>(n) * nMul;
        nSum %= nDivide;
        nMul = nMul * 31 % nDivide;
    }

    cout << nSum;
}