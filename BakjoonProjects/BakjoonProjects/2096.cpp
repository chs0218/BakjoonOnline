#include <iostream>
using namespace std;
/*
다이나믹 프로그래밍
슬라이딩 윈도우
*/
int N;
int board[100000][3];
int maxdp[2][3];
int mindp[2][3];
int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> board[i][0] >> board[i][1] >> board[i][2];

    maxdp[1][0] = board[0][0];
    maxdp[1][1] = board[0][1];
    maxdp[1][2] = board[0][2];

    mindp[1][0] = board[0][0];
    mindp[1][1] = board[0][1];
    mindp[1][2] = board[0][2];

    for (int i = 1; i < N; ++i)
    {
        maxdp[0][0] = maxdp[1][0];
        maxdp[0][1] = maxdp[1][1];
        maxdp[0][2] = maxdp[1][2];

        maxdp[1][0] = max(maxdp[0][0] + board[i][0], maxdp[0][1] + board[i][0]);
        maxdp[1][1] = max(maxdp[0][0] + board[i][1], maxdp[0][1] + board[i][1]);
        maxdp[1][1] = max(maxdp[1][1], maxdp[0][2] + board[i][1]);
        maxdp[1][2] = max(maxdp[0][1] + board[i][2], maxdp[0][2] + board[i][2]);

        mindp[0][0] = mindp[1][0];
        mindp[0][1] = mindp[1][1];
        mindp[0][2] = mindp[1][2];

        mindp[1][0] = min(mindp[0][0] + board[i][0], mindp[0][1] + board[i][0]);
        mindp[1][1] = min(mindp[0][0] + board[i][1], mindp[0][1] + board[i][1]);
        mindp[1][1] = min(mindp[1][1], mindp[0][2] + board[i][1]);
        mindp[1][2] = min(mindp[0][1] + board[i][2], mindp[0][2] + board[i][2]);
    }

    int ansMax = max(maxdp[1][0], maxdp[1][1]);
    ansMax = max(ansMax, maxdp[1][2]);
    int ansMin = min(mindp[1][0], mindp[1][1]);
    ansMin = min(ansMin, mindp[1][2]);

    cout << ansMax << " " << ansMin;
}