#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct FInfo {
    int X;
    int Y;
    int Cost;
};
bool operator<(FInfo lhs, FInfo rhs)
{
    return lhs.Cost > rhs.Cost;
}
int Dx[] = { -1, 0, 1, 0 };
int Dy[] = { 0, -1, 0, 1 };
int Ans[100][100];
int N, M;
vector<string> Maze;
bool IsValidCoord(int X, int Y)
{
    if (X < 0) return false;
    if (Y < 0) return false;
    if (X >= M) return false;
    if (Y >= N) return false;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> M >> N;
    Maze.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> Maze[i];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            Ans[i][j] = 1e9;

    priority_queue<FInfo> Pq;
    Ans[0][0] = 0;
    Pq.push({ 0, 0, 0 });

    while (!Pq.empty())
    {
        FInfo CurInfo = Pq.top();
        Pq.pop();

        if (Ans[CurInfo.Y][CurInfo.X] < CurInfo.Cost) continue;

        for (int i = 0; i < 4; ++i)
        {
            FInfo NextInfo;
            NextInfo.X = CurInfo.X + Dx[i];
            NextInfo.Y = CurInfo.Y + Dy[i];

            if (!IsValidCoord(NextInfo.X, NextInfo.Y)) continue;

            Maze[NextInfo.Y][NextInfo.X] == '1' ? NextInfo.Cost = CurInfo.Cost + 1 : NextInfo.Cost = CurInfo.Cost;

            if (Ans[NextInfo.Y][NextInfo.X] > NextInfo.Cost)
            {
                Ans[NextInfo.Y][NextInfo.X] = NextInfo.Cost;
                Pq.push(NextInfo);
            }
        }
    }

    cout << Ans[N - 1][M - 1];
}