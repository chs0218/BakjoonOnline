#include <iostream>
#include <algorithm>
using namespace std;
int ccw(pair<long long, long long> vec1, pair<long long, long long> vec2)
{
    long long ret = vec1.first * vec2.second - vec2.first * vec1.second;
    if (ret == 0) return 0;
    if (ret < 0) return -1;
    return 1;
}
int main()
{
    pair<long long, long long> v[4];

    for (int i = 0; i < 4; ++i)
        cin >> v[i].first >> v[i].second;

    int ret[4];
    ret[0] = ccw(make_pair(v[1].first - v[0].first, v[1].second - v[0].second),
        make_pair(v[2].first - v[0].first, v[2].second - v[0].second));
    ret[1] = ccw(make_pair(v[1].first - v[0].first, v[1].second - v[0].second),
        make_pair(v[3].first - v[0].first, v[3].second - v[0].second));
    ret[2] = ccw(make_pair(v[3].first - v[2].first, v[3].second - v[2].second),
        make_pair(v[0].first - v[2].first, v[0].second - v[2].second));
    ret[3] = ccw(make_pair(v[3].first - v[2].first, v[3].second - v[2].second),
        make_pair(v[1].first - v[2].first, v[1].second - v[2].second));

    int ans = 0;
    if (ret[0] * ret[1] == 0 && ret[2] * ret[3] == 0)
    {
        if (v[0] > v[1]) swap(v[0], v[1]);
        if (v[2] > v[3]) swap(v[2], v[3]);
        if (v[0] <= v[3] && v[1] >= v[2]) 
            ans = 1;
    }
    else {
        if (ret[0] * ret[1] <= 0 && ret[2] * ret[3] <= 0)
            ans = 1;
    }
    cout << ans;
}