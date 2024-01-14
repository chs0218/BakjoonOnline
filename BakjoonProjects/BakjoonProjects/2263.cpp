#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int N;
array<int, 100000> vInorder;
array<int, 100000> vPreorder;

void dfs(int io_F, int io_L, int po_F, int po_L)
{
    if (io_F > io_L || po_F > po_L) return;

    int cur = vPreorder[po_L];
    cout << cur << " ";

    int dis = -1;
    for (int i = 0; io_F + i <= io_L; ++i)
    {
        if (vInorder[io_F + i] == cur) {
            dis = i;
            break;
        }
    }

    dfs(io_F, io_F + dis - 1, po_F, po_F + dis - 1);
    dfs(io_F + dis + 1, io_L, po_F + dis, po_L - 1);
}
int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> vInorder[i];

    for (int i = 0; i < N; ++i)
        cin >> vPreorder[i];

    dfs(0, N - 1, 0, N - 1);
}