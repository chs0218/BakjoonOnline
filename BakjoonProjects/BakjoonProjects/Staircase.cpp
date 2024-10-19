#include <iostream>
using namespace std;
int main()
{
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
            cout << " ";
        for (int j = 0; j < i; ++j)
            cout << "#";
        cout << "\n";
    }
}