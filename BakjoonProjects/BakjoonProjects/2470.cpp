#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int N;
int value[100000];
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> value[i];

    sort(value, value + N);

    int l = 0, r = N - 1;
    int ans[2] = { 0, N - 1 };
    int min = abs(value[l] + value[r]);

    while (l < r)
    {
        int cur = value[l] + value[r];

        if (abs(cur) < min) {
            ans[0] = l;
            ans[1] = r;
            min = abs(cur);
        }

        if (cur < 0) ++l;
        else --r;
    }

    cout << value[ans[0]] << " " << value[ans[1]];
}