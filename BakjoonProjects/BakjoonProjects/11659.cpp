#include <iostream>
using namespace std;
int num[10'0001];
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nNum, nPlus;
    cin >> nNum >> nPlus;

    for (int i = 1; i <= nNum; ++i)
    {
        cin >> num[i];
        if (i > 0) num[i] += num[i - 1];
    }

    for (int i = 0; i < nPlus; ++i)
    {
        int ans = 0;

        int lhs = 0, rhs = 0;
        cin >> lhs >> rhs;

        cout << num[rhs] - num[lhs - 1] << "\n";
    }
}