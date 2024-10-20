#include <iostream>
#include <algorithm>
using namespace std;
/*
백트래킹
*/
int N, M;
int arr[8];
int nSeq[8];
bool bVisited[8];
void Seq(int nDepth, int nPrevIndex) {
    if (nDepth == M) {
        for (int i = 0; i < M; ++i)
            cout << nSeq[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = nPrevIndex; i < N; ++i)
    {
        nSeq[nDepth] = arr[i];
        Seq(nDepth + 1, i);
    }
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr, arr + N);

    Seq(0, 0);
}