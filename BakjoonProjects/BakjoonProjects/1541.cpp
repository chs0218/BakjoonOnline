#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;

    int n = 0;
    int ans = 0;

    char c = ' ';
    bool bMinus = false;
    bool bOperator = true;

    while (str.length()) {
        char c = *str.begin();
        str.erase(str.begin());

        if (c >= '0' && c <= '9')
            n = n * 10 + static_cast<int>(c - '0');
        else
        {
            if (bMinus) ans -= n;
            else {
                if (bOperator && !bMinus) ans += n;
                else ans -= n;

                if (c == '+') bOperator = true;
                else {
                    bMinus = true;
                    bOperator = false;
                }
            }
            n = 0;
        }
    }

    if (bOperator && !bMinus) ans += n;
    else ans -= n;

    cout << ans;
}