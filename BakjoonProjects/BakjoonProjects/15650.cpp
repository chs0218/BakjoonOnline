#include <iostream>
using namespace std;
/*
백트래킹
*/
int N, M;
int nSeq[8];
void Seq(int nDepth, int nPrevious) {
    if (nDepth == M) {
        for (int i = 0; i < M; ++i)
            cout << nSeq[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = nPrevious + 1; i <= N; ++i)
    {
        nSeq[nDepth] = i;
        Seq(nDepth + 1, i);
    }
}
int main()
{
    cin >> N >> M;
    Seq(0, 0);
}