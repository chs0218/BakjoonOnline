#include <iostream>
#include <vector>
using namespace std;
/*
기하학
다각형의 넓이
*/
double GetSpace(pair<int, int> v1, pair<int, int> v2, pair<int, int> v3)
{
    pair<long long, long long> vec1 = make_pair(v2.first - v1.first, v2.second - v1.second);
    pair<long long, long long> vec2 = make_pair(v3.first - v1.first, v3.second - v1.second);

    long long ll = (vec1.first * vec2.second - vec1.second * vec2.first);
    double ret = static_cast<double>(ll) / static_cast<double>(2.0);
    return ret;
}
int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; ++i)
        cin >> v[i].first >> v[i].second;

    double ans = 0.0f;
    for (int i = 1; i < N - 1; ++i)
        ans += GetSpace(v[0], v[i], v[i + 1]);

    cout << fixed;
    cout.precision(1);
    cout << abs(ans);
}