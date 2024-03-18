#include <iostream>
using namespace std;
int main()
{
    int N, F;
    cin >> N >> F;

    N = N / 100 * 100;

    int ans = 0;
    for (int i = N; ; ++i)
    {
        if (i % F == 0) {
            ans = i - N;
            break;
        }
    }

    if (ans < 10) cout << "0" << ans;
    else cout << ans;
}