#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nOperate;
    cin >> nOperate;

    auto cmp = [](int lhs, int rhs) {
        if (abs(lhs) == abs(rhs)) {
            return lhs > rhs;
        }
        return abs(lhs) > abs(rhs);
    };

    priority_queue<int, std::vector<int>, decltype(cmp)> pqNum(cmp);

    for (int i = 0; i < nOperate; ++i)
    {
        int n;
        cin >> n;
        if (n != 0) pqNum.push(n);
        else {
            if (pqNum.empty())
                cout << "0\n";
            else {
                cout << pqNum.top() << "\n";
                pqNum.pop();
            }
        }
    }
}