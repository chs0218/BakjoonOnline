#include <iostream>
using namespace std;
int N, Jimin, HanSu;
int main()
{
    cin >> N >> Jimin >> HanSu;

    if (Jimin > HanSu)
    {
        int Tmp = Jimin;
        Jimin = HanSu;
        HanSu = Tmp;
    }

    int ans = 1;
    while (1)
    {
        if (Jimin % 2 == 1 && HanSu == Jimin + 1)
            break;

        Jimin = (Jimin + 1) / 2;
        HanSu = (HanSu + 1) / 2;
        ++ans;
    }

    cout << ans;
}