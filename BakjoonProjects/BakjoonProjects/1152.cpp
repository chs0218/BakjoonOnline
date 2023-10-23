#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);

    if (str[0] == ' ')
        str = str.substr(1);
    if (str[str.length() - 1] == ' ')
        str = str.substr(0, str.length() - 1);

    int count = 1;

    if (str.length() == 0)
        count = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == ' ')
            ++count;
    }

    cout << count << endl;
}