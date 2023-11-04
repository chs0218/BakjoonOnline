#include <iostream>
#include <queue>
#include <numeric>
using namespace std;
int main()
{
	int nCard;
	cin >> nCard;

	queue<int> arrCards;

	for (int i = 0; i < nCard; ++i)
		arrCards.push(i + 1);

	bool bChk = false;
	while (arrCards.size() > 1)
	{
		if (bChk) {
			int n = arrCards.front();
			arrCards.pop();
			arrCards.push(n);
			bChk = false;
		}
		else {
			arrCards.pop();
			bChk = true;
		}
	}

	cout << arrCards.front();
}