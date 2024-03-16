#include <iostream>
using namespace std;
int main()
{
    int M, curBall = 1;
    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int X, Y;
        cin >> X >> Y;

        if (X == Y) continue;
        if (X == curBall)
            curBall = Y;
        else if (Y == curBall)
            curBall = X;
    }
    cout << curBall;
}