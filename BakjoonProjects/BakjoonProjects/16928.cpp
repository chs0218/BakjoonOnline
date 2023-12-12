#include <iostream>
#include <queue>
using namespace std;
bool bVisited[101];
int nNode[101];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nNodeUp, nNodeDown;
    cin >> nNodeUp >> nNodeDown;

    for (int i = 0; i < nNodeUp + nNodeDown; ++i)
    {
        int nStart, nEnd;
        cin >> nStart >> nEnd;
        nNode[nStart] = nEnd;
    }

    queue<pair<int, int>> qInfo;
    qInfo.push(make_pair(1, 0));

    int ans = 0;
    while (!qInfo.empty()) {
        pair<int, int> info = qInfo.front();
        qInfo.pop();

        if (nNode[info.first] != 0) {
            info.first = nNode[info.first];
        }

        if (info.first == 100) {
            ans = info.second;
            break;
        }

        for (int i = 1; i <= 6; ++i) {
            if (info.first + i <= 100 && !bVisited[info.first + i]) {
                bVisited[info.first + i] = true;
                qInfo.push(make_pair(info.first + i, info.second + 1));
            }
        }
    }
    cout << ans;
}