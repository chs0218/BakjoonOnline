#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nInput;
    cin >> nInput;

    priority_queue<int, vector<int>, greater<int>> pqNums;

    for (int i = 0; i < nInput; ++i)
    {
        int n;
        cin >> n;

        if (n != 0) pqNums.push(n);
        else {
            if (pqNums.size()) {
                cout << pqNums.top() << "\n";
                pqNums.pop();
            }
            else
                cout << "0\n";
        }
    }
}