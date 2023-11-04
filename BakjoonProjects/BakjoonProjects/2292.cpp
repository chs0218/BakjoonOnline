#include <iostream>
using namespace std;
int main()
{
	int nRoomNum;

	cin >> nRoomNum;

	int nIncreaseValue = 1;
	int nAns = 1, nJudge = 1;
	while (nRoomNum > nJudge) {
		nJudge = nJudge + 6 * nIncreaseValue++;
		++nAns;
	}
	cout << nAns;
}