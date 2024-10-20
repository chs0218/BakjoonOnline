#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int L;
    cin >> L;

    vector<int> S(L);
    for (int i = 0; i < L; ++i)
        cin >> S[i];

    int nPrint;
    cin >> nPrint;

    sort(S.begin(), S.end());

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int i = 0; i < S.size(); ++i)
    {
        int start;
        i == 0 ? start = 0 : start = S[i - 1];

        int end = S[i];
        
        int nCount = 0;
        for (int j = 0; j < (end - start) / 2; ++j)
        {
            if (nCount++ >= 50) break;
            long long value = static_cast<long long>(j + 1) * static_cast<long long>(end - (start + j + 1));
            pq.push({ value, start + (j + 1) });
            pq.push({ value, end - (j + 1) });
        }

        pq.push({ 0, end });
    }

    while (!pq.empty() && nPrint-- > 0)
    {
        pair<long long, int> result = pq.top();
        pq.pop();

        cout << result.second << " ";
    }

    int next = S.back() + 1;
    while (nPrint-- > 0)
    {
        cout << next++ << " ";
    }
}