#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;

    vector<int> vValue;
    for (int i = 0; i < N; ++i)
    {
        int A, B;
        cin >> A >> B;

        vValue.push_back(A - B);
    }

    sort(vValue.begin(), vValue.end());

    int ans = 1;
    if (N % 2 == 0) ans = vValue[N / 2] - vValue[N / 2 - 1] + 1;
    cout << ans;
}