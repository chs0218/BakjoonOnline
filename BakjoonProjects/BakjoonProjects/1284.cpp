#include <iostream>
using namespace std;
int main()
{
    while (1)
    {
        int N;
        cin >> N;

        if (N == 0)
        {
            break;
        }

        int ans = 1;
        while (N) {
            int curNum = N % 10;

            if (curNum == 1)
            {
                ans += 2;
            }
            else if (curNum == 0)
            {
                ans += 4;
            }
            else
            {
                ans += 3;
            }

            N /= 10;
            ans += 1;
        }

        cout << ans << "\n";
    }
}