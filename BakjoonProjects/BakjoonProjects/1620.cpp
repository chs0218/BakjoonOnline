#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nMonster, nInput;
    cin >> nMonster >> nInput;

    map<string, int> mpName;
    map<int, string> mpNum;

    int n = 1;
    for (int i = 0; i < nMonster; ++i)
    {
        string str;
        cin >> str;
        mpName.insert(make_pair(str, n));
        mpNum.insert(make_pair(n++, str));
    }

    for (int i = 0; i < nInput; ++i)
    {
        string str;
        cin >> str;

        if (isdigit(str[0]))
        {
            int num = stoi(str);
            auto it = mpNum.find(num);
            cout << it->second << "\n";
        }
        else
        {
            auto it = mpName.find(str);
            cout << it->second << "\n";
        }
    }
}