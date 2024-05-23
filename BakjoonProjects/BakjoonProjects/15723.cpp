#include <iostream>
#include <string>
#include <limits>
using namespace std;
bool Proposition[26][26];
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 26; ++i)
        Proposition[i][i] = true;

    for (int i = 0; i < n; ++i)
    {
        string str;

        cin >> str;
        int a = str[0] - 'a';
        cin >> str;
        cin >> str;
        int b = str[0] - 'a';

        Proposition[a][b] = true;
    }

    for (int k = 0; k < 26; ++k)
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
            {
                if (Proposition[i][k] && Proposition[k][j])
                    Proposition[i][j] = true;
            }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        string str;

        cin >> str;
        int a = str[0] - 'a';
        cin >> str;
        cin >> str;
        int b = str[0] - 'a';

        if (Proposition[a][b])
            cout << "T\n";
        else
            cout << "F\n";
    }
}