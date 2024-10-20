#include <iostream>
#include <string>
using namespace std;
/*
자료 구조
문자열
스택
*/
int main()
{
    string strTotal, strBomb;
    cin >> strTotal >> strBomb;

    string ans;
    for (int i = 0; i < strTotal.size(); ++i)
    {
        ans += strTotal[i];
        if (ans.size() >= strBomb.size() && ans.back() == strBomb.back())
        {
            bool explode = true;
            for (int j = 0; j < strBomb.size(); ++j)
            {
                char rhs = *(ans.rbegin() + j);
                char lhs = *(strBomb.rbegin() + j);
                if (rhs != lhs)
                {
                    explode = false;
                    break;
                }
            }

            if (explode) {
                for (int j = 0; j < strBomb.size(); ++j)
                    ans.erase(ans.end() - 1);
            }
        }
    }

    if (ans.empty()) cout << "FRULA";
    else cout << ans;
}