#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<long long> liquidV(N);

    for (int i = 0; i < N; ++i)
        cin >> liquidV[i];

    int lhs = 0, rhs = N - 1;
    long long ansSum = abs(liquidV[lhs] + liquidV[rhs]);
    long long v1 = liquidV[lhs], v2 = liquidV[rhs];
    while (lhs < rhs)
    {
        long long sum = liquidV[lhs] + liquidV[rhs];
        if (abs(sum) < ansSum) {
            v1 = liquidV[lhs];
            v2 = liquidV[rhs];
            ansSum = abs(sum);
        }
        if (sum < 0) ++lhs;
        else --rhs;
    }

    cout << v1 << " " << v2 << "\n";
}