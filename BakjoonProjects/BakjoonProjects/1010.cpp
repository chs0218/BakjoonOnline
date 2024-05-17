#include <iostream>
using namespace std;

int T, N, M;
long long ans[30][30];

int main()
{
    cin >> T;

    for (int i = 1; i < 30; ++i)
        ans[1][i] = i;

    for (int i = 2; i < 30; ++i)
    {
        for (int j = i; j < 30; ++j)
        {
            ans[i][j] = ans[i][j - 1] + ans[i - 1][j - 1];
        }
    }

    for (int i = 0; i < T; ++i)
    {
        cin >> N >> M;
        cout << ans[N][M] << "\n";
    }
}