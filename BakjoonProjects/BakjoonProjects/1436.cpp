#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int number = 666;
    while (1)
    {
        if (to_string(number).find("666") != string::npos)
        {
            if (--n == 0)
            {
                cout << number << "\n";
                break;
            }
        }

        number += 1;
    }
}