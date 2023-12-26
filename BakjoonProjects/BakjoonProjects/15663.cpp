#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int N, M;
int arr[8];
int nSeq[8];
bool bVisited[8];
void Seq(int nDepth) {
    if (nDepth == M) {
        for (int i = 0; i < M; ++i)
            cout << nSeq[i] << " ";
        cout << "\n";
        return;
    }

    int n = 0;
    for (int i = 0; i < N; ++i)
    {
        if (!bVisited[i] && n != arr[i]) {
            bVisited[i] = true;
            n = arr[i];
            nSeq[nDepth] = arr[i];
            Seq(nDepth + 1);
            bVisited[i] = false;
        }
    }
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr, arr + N);

    Seq(0);
}