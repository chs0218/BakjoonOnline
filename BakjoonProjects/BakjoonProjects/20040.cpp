#include <iostream>
using namespace std;
int parent[500000];
int GetParent(int n)
{
    if (parent[n] == n) return n;
    return parent[n] = GetParent(parent[n]);
}
bool DrawLine(int v1, int v2)
{
    int p1 = GetParent(v1);
    int p2 = GetParent(v2);

    if (p1 == p2) return false;

    if (p1 < p2) parent[p2] = p1;
    else parent[p1] = p2;
    return true;
}
int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        parent[i] = i;

    int ans = 0;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;

        if (!DrawLine(v1, v2))
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans;
}