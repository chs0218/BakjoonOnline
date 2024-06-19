#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
int Dp[1001][16][16];
vector<pair<int, int>> ScoreWB;

int Solve(int WhiteNum, int BlackNum, int Depth)
{
    if (WhiteNum == 15 && BlackNum == 15) return 0;
    if (Depth == ScoreWB.size()) return -1e10;
    int& Ret = Dp[Depth][WhiteNum][BlackNum];
    if (Ret != -1) return Ret;

    Ret = Solve(WhiteNum, BlackNum, Depth + 1);
    if (WhiteNum < 15) Ret = max(Ret, Solve(WhiteNum + 1, BlackNum, Depth + 1) + ScoreWB[Depth].first);
    if (BlackNum < 15) Ret = max(Ret, Solve(WhiteNum, BlackNum + 1, Depth + 1) + ScoreWB[Depth].second);

    return Ret;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    while (scanf("%d %d", &A, &B) != EOF) {
        ScoreWB.push_back({ A, B });
    }

    memset(Dp, -1, sizeof(Dp));

    cout << Solve(0, 0, 0) << "\n";
}