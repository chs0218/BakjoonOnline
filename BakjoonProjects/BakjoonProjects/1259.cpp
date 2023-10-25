#include <iostream>
#include <string>
using namespace std;
int main()
{
    while (1)
    {
        string str;
        cin >> str;

        if (str == "0") break;

        string strLeft{ str.begin(), str.begin() + str.size() / 2 };
        string strRight{ str.rbegin(), str.rbegin() + str.size() / 2 };

        if (strLeft == strRight) cout << "yes\n";
        else cout << "no\n";
    }
}