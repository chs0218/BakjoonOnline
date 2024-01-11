#include <iostream>
#include <algorithm>
using namespace std;
long long liquid[5000];
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> liquid[i];

    sort(liquid, liquid + N);

    long long ansSum = 1e11;
    int ans[3] = { 0, 0, 0 };
    for (int i = 0; i < N - 2; ++i)
    {
        int v[3] = { i, i + 1, N - 1 };

        while (v[1] < v[2])
        {
            long long sum = liquid[v[0]] + liquid[v[1]] + liquid[v[2]];
           
            if (abs(sum) < ansSum) {
                ansSum = abs(sum);
                ans[0] = v[0];
                ans[1] = v[1];
                ans[2] = v[2];
            }

            if (sum < 0) ++v[1];
            else --v[2];
        }
    }

    for (int i = 0; i < 3; ++i)
        cout << liquid[ans[i]] << " ";
}