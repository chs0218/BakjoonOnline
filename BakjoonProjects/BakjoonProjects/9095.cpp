#include <iostream>
#include <queue>
using namespace std;
struct Info {
    int nTask;
    int sum;
};
bool bVisited[4][11];
int main()
{
    int nTestCase = 0;
    cin >> nTestCase;

    for (int i = 0; i < nTestCase; ++i)
    {
        int ans = 0;
        int num = 0;

        cin >> num;

        bVisited[1][0] = true;
        bVisited[2][0] = true;
        bVisited[3][0] = true;

        queue<Info> qInfo;
        qInfo.push({ 0, 1 });
        qInfo.push({ 0, 2 });
        qInfo.push({ 0, 3 });

        while (!qInfo.empty()) {
            Info info = qInfo.front();
            qInfo.pop();

            if (info.sum > num) continue;
            if (info.sum == num) {
                ++ans;
                continue;
            }

            for (int i = 1; i <= 3; ++i) {
                if (!bVisited[i][info.nTask + 1])
                    qInfo.push({ info.nTask + 1, info.sum + i });
            }
        }

        cout << ans << "\n";
    }
}