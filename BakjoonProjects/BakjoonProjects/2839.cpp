#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int nKg;
	cin >> nKg;

	int ans = -1;
	bool bChk = false;
	for (int i = nKg / 5; i >= 0; --i)
	{
		int nLeft = nKg - 5 * i;

		if (nLeft % 3 == 0) {
			bChk = true;
			ans = i + nLeft / 3;
		}

		if (bChk) break;
	}

	cout << ans;
}