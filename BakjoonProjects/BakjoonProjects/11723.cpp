#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int Operate(string str) {
    if (str == "add") return 0;
    if (str == "remove") return 1;
    if (str == "check") return 2;
    if (str == "toggle") return 3;
    if (str == "all") return 4;
    if (str == "empty") return 5;
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nOperator = 0;
    cin >> nOperator;

    int chkNum = 0;
    for (int i = 0; i < nOperator; ++i)
    {
        string command = "";
        int rhs = 0;

        cin >> command;

        switch (Operate(command)) {
        case 0:
            cin >> rhs;
            chkNum |= static_cast<int>(pow(2, rhs - 1));
            break;
        case 1:
            cin >> rhs;
            chkNum &= (static_cast<int>(pow(2, 20)) - 1) - static_cast<int>(pow(2, rhs - 1));
            break;
        case 2:
            cin >> rhs;
            if(chkNum & static_cast<int>(pow(2, rhs - 1))) 
                cout << "1\n";
            else
                cout << "0\n";
            break;
        case 3:
            cin >> rhs;
            chkNum ^= static_cast<int>(pow(2, rhs - 1));
            break;
        case 4:
            chkNum = static_cast<int>(pow(2, 20)) - 1;
            break;
        case 5:
            chkNum = 0;
            break;
        default:
            break;
        }
    }
}