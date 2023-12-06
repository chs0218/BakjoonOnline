#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
    int nTestCase;
    cin >> nTestCase;
    for (int i = 0; i < nTestCase; ++i)
    {
        string strCommand;
        string strArray;
        int nElement;
        deque<int> dqNums;

        cin >> strCommand;
        cin >> nElement;
        cin >> strArray;

        int n = 0;

        for (const char& c : strArray) {
            if (isdigit(c)) {
                n = n * 10 + static_cast<int>(c - '0');
            }
            else if (n != 0) {
                dqNums.push_back(n);
                n = 0;
            }
        }

        bool bReverse = false;
        bool bError = false;
        for (const char& c : strCommand) {
            if (c == 'R') bReverse = !bReverse;
            else {
                if (dqNums.empty()) {
                    bError = true;
                    cout << "error\n";
                    break;
                }
                if (bReverse) dqNums.pop_back();
                else dqNums.pop_front();
            }
        }

        if (!bError) {
            cout << "[";
            if (bReverse) {
                for (auto it = dqNums.rbegin(); it < dqNums.rend(); ++it)
                {
                    if (it == dqNums.rend() - 1) cout << *it;
                    else cout << *it << ",";
                }
            }
            else {
                for (auto it = dqNums.begin(); it < dqNums.end(); ++it)
                {
                    if (it == dqNums.end() - 1) cout << *it;
                    else cout << *it << ",";
                }
            }
            cout << "]\n";
        }
        
    }
}