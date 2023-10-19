/*
������ ���� N���� ��ǥ X1, X2, ..., XN�� �ִ�. �� ��ǥ�� ��ǥ ������ �����Ϸ��� �Ѵ�.

Xi�� ��ǥ ������ ��� X'i�� ���� Xi > Xj�� �����ϴ� ���� �ٸ� ��ǥ Xj�� ������ ���ƾ� �Ѵ�.

X1, X2, ..., XN�� ��ǥ ������ ������ ��� X'1, X'2, ..., X'N�� ����غ���.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> vNormal(n), vSort(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> vNormal[i];
        vSort[i] = vNormal[i];
    }

    sort(vSort.begin(), vSort.end());
    vSort.erase(unique(vSort.begin(), vSort.end()), vSort.end());

    for (const int& i : vNormal)
    {
        auto it = lower_bound(vSort.begin(), vSort.end(), i);
        cout << it - vSort.begin() << " ";
    }
}