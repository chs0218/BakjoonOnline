#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int A, B;
        cin >> A >> B;

        int tmp = 1;
        for (int i = 0; i < B; ++i)
            tmp = (tmp * A) % 10;

        if (tmp == 0) cout << "10\n";
        else cout << tmp << endl;
    }
}