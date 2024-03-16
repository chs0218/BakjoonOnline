#include <string>
#include <iostream>

using namespace std;
int AlphaNum[26];
int main()
{
    string Name;
    cin >> Name;

    for (const char c : Name)
        ++AlphaNum[c - 'A'];

    string AnsName = "";
    char MiddleChar = '-';
    for (int i = 0; i < 26; ++i)
    {
        if (AlphaNum[i] % 2 != 0)
        {
            if (MiddleChar != '-')
            {
                cout << "I\'m Sorry Hansoo";
                return 0;
            }
            else
            {
                MiddleChar = 'A' + i;
                AlphaNum[i] -= 1;
            }
        }

        while (AlphaNum[i] > 0) {
            AnsName.push_back('A' + i);
            AlphaNum[i] -= 2;
        }
    }

    for (auto it = AnsName.begin(); it != AnsName.end(); ++it)
        cout << *it;
    if (MiddleChar != '-') cout << MiddleChar;
    for (auto it = AnsName.rbegin(); it != AnsName.rend(); ++it)
        cout << *it;
}