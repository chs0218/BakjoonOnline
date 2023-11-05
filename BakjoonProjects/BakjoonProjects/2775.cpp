#include <iostream>
#include <array>
#include <vector>
#include <numeric>
using namespace std;
vector<array<int, 14>> vFloor;
int GetNum(int k, int n) {
	if (vFloor[k][n] != 0) return vFloor[k][n];
	if (n == 0) return 1;
	return GetNum(k, n - 1) + GetNum(k - 1, n);
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int nCase;
	cin >> nCase;

	vFloor.push_back(array<int, 14>{});
	iota(vFloor[0].begin(), vFloor[0].end(), 1);

	for (int i = 0; i < nCase; ++i)
	{
		int k, n;
		cin >> k >> n;

		if (vFloor.size() < k + 1) {
			vFloor.resize(k + 1);
		}

		cout << GetNum(k, n - 1) << "\n";
	}
}