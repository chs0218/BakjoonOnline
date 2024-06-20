#include <iostream>
using namespace std;
int Cost[101][101];
int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j) Cost[i][j] = 0;
            else Cost[i][j] = 1e9;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        if(Cost[A][B] > C) Cost[A][B] = C;
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                Cost[i][j] = min(Cost[i][j], Cost[i][k] + Cost[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (Cost[i][j] == 1e9) cout << "0 ";
            else cout << Cost[i][j] << " ";
        }
        cout << "\n";
    }
}