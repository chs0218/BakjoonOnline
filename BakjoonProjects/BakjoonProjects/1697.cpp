#include <iostream>
#include <queue>
using namespace std;
struct Info {
    int nCurr;
    int nCost;
};
bool bVisited[10'0000];
int main()
{
    int nSubin, nTarget;
    cin >> nSubin >> nTarget;

    queue<Info> qInfo;
    qInfo.push(Info{ nSubin, 0 });

    int ans = 0;
    while (1) {
        Info info = qInfo.front();
        qInfo.pop();

        if (info.nCurr == nTarget)
        {
            ans = info.nCost;
            break;
        }

        if (info.nCurr - 1 >= 0 &&
            info.nCurr - 1 <= 10'0000 &&
            !bVisited[info.nCurr - 1])
        {
            bVisited[info.nCurr - 1] = true;
            qInfo.push(Info{ info.nCurr - 1, info.nCost + 1 });
        }
        
        if (info.nCurr + 1 >= 0 &&
            info.nCurr + 1 <= 10'0000 &&
            !bVisited[info.nCurr + 1])
        {
            bVisited[info.nCurr + 1] = true;
            qInfo.push(Info{ info.nCurr + 1, info.nCost + 1 });
        }

        if (info.nCurr * 2 >= 0 &&
            info.nCurr * 2 <= 10'0000 &&
            !bVisited[info.nCurr * 2])
        {
            bVisited[info.nCurr * 2] = true;
            qInfo.push(Info{ info.nCurr * 2, info.nCost + 1 });
        }
    }

    cout << ans;
}