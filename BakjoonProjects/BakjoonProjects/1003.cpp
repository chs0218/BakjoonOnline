#include <iostream>
#include <memory.h>
using namespace std;
int ans[41][2];
void fibo(int n) {
    if (ans[n - 1][0] == -1)
        fibo(n - 1);

    if (ans[n - 2][0] == -1)
        fibo(n - 2);

    ans[n][0] = ans[n - 1][0] + ans[n - 2][0];
    ans[n][1] = ans[n - 1][1] + ans[n - 2][1];
}
int main()
{
    int nCase;
    cin >> nCase;

    memset(ans, -1, sizeof(ans));

    ans[0][0] = 1;
    ans[0][1] = 0;
    ans[1][0] = 0;
    ans[1][1] = 1;

    for (int i = 0; i < nCase; ++i)
    {
        int n;
        cin >> n;
        if (n >= 2)
            fibo(n);
        cout << ans[n][0] << " " << ans[n][1] << "\n";
    }
}
