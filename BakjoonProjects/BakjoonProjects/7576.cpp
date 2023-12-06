#include <iostream>
#include <queue>
using namespace std;
int nTomatoState[1000][1000];
struct Info {
    int i;
    int j;
    int cost;
};
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nWidth, nHeight;
    cin >> nWidth >> nHeight;

    int nTargetTomato = 0;
    queue<Info> vInfos;
    for (int i = 0; i < nHeight; ++i) {
        for (int j = 0; j < nWidth; ++j) {
            cin >> nTomatoState[i][j];

            if (nTomatoState[i][j] == 1)
                vInfos.push(Info{ i, j, 0 });
            else if (nTomatoState[i][j] == 0)
                ++nTargetTomato;
        }
    }

    int ans = 0;
    while (!vInfos.empty()) {
        Info info = vInfos.front();
        vInfos.pop();

        ans = max(ans, info.cost);

        for (int i = 0; i < 4; ++i) {
            int nx = info.j + dx[i];
            int ny = info.i + dy[i];

            if (nx < 0 || nx >= nWidth || ny < 0 || ny >= nHeight)
                continue;

            if (nTomatoState[ny][nx] == 0) {
                nTomatoState[ny][nx] = 1;
                --nTargetTomato;
                vInfos.push(Info{ ny, nx, info.cost + 1 });
            }
        }
    }

    if (nTargetTomato) cout << "-1";
    else cout << ans;
}