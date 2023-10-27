#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        int tmp = i;
        while (tmp) {
            if (tmp % 5 == 0)
            {
                ++count;
                tmp /= 5;
            }
            else
                break;
        }
    }

    cout << count;
}