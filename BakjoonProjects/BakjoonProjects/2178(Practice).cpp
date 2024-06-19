#include <iostream>
#include <memory.h>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct FInfo {
    int X;
    int Y;
    int Cost;
};
bool Visited[100][100];
int DeltaX[] = {-1, 0, 1, 0};
int DeltaY[] = {0, -1, 0, 1};
int N, M;
bool CheckValidCoord(int X, int Y)
{
    if (X < 0) return false;
    if (Y < 0) return false;
    if (X >= M) return false;
    if (Y >= N) return false;
    return true;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    vector<string> Maze(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> Maze[i];
    }

    memset(Visited, false, sizeof(Visited));

    queue<FInfo> Info;
    Visited[0][0] = true;
    Info.push(FInfo{ 0, 0, 1 });

    while (!Info.empty())
    {
        FInfo Cur = Info.front();
        Info.pop();

        if (Cur.Y == N - 1 && Cur.X == M - 1)
        {
            cout << Cur.Cost;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NextX = Cur.X + DeltaX[i];
            int NextY = Cur.Y + DeltaY[i];

            if (CheckValidCoord(NextX, NextY) &&
                Maze[NextY][NextX] == '1' &&
                !Visited[NextY][NextX])
            {
                Visited[NextY][NextX] = true;
                Info.push(FInfo{ NextX, NextY, Cur.Cost + 1 });
            }
        }
    }


}