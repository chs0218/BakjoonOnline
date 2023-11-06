#include <iostream>
#include <array>
using namespace std;
array<int, 10001> arrNums;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nSize;
    cin >> nSize;

    for (int i = 0; i < nSize; ++i)
    {
        int n;
        cin >> n;
        ++arrNums[n];
    }
    

    for (int i = 0; i < 10001; ++i)
    {
        for (int j = 0; j < arrNums[i]; ++j)
            cout << i << "\n";
    }
}