#include <iostream>
#include <vector>
using namespace std;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int nCard, nGoal;
	cin >> nCard >> nGoal;

	vector<int> vCards(nCard);
	for (int i = 0; i < nCard; ++i)
		cin >> vCards[i];

	int ans = 0;

	for (int i = 0; i < nCard - 2; ++i)
	{
		for (int j = i + 1; j < nCard - 1; ++j)
		{
			for (int k = i + 2; k < nCard; ++k)
			{
				if (vCards[i] + vCards[j] + vCards[k] <= nGoal)
					ans = max(ans, vCards[i] + vCards[j] + vCards[k]);
			}
		}
	}

	cout << ans;
}