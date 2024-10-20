#include <iostream>
#include <memory.h>
using namespace std;
/*
±×·¡ÇÁ ÀÌ·Ð
±×·¡ÇÁ Å½»ö
±íÀÌ ¿ì¼± Å½»ö
*/
int line[100001];
int visited[100001];
int dfs(int n, int curDepth, int preDepth)
{
    if (visited[n] > 0)
        return curDepth - visited[n];
    if (visited[n] == -1) return -1;

    if (n == line[n]) {
        visited[n] = -1;
        return 1;
    }

    visited[n] = curDepth;
    int ret = dfs(line[n], curDepth + 1, curDepth);
    visited[n] = -1;
    return ret;
}
int main()
{
    int T;
    cin >> T;

    while (T) {
        memset(visited, false, sizeof(visited));

        int N;
        cin >> N;

        for (int i = 1; i <= N; ++i)
            cin >> line[i];

        int ans = 0;
        for (int i = 1; i <= N; ++i)
        {
            int ret = dfs(i, 1, 0);
            if(ret > 0) ans += ret;
        }
        cout << N - ans << "\n";

        --T;
    }
}