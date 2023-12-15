#include <iostream>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;
bool bVisited[10000];

void bfs(int prevN, int goalN) {
	queue<pair<int, string>> qInfo;

	bVisited[prevN] = true;
	qInfo.push(make_pair(prevN, ""));

	while (!qInfo.empty()) {
		pair<int, string> info = qInfo.front();
		int num = info.first;
		string cmd = info.second;
		qInfo.pop();

		if (num == goalN) {
			cout << cmd << "\n";
			break;
		}

		int convertN = 0;
		convertN = (num * 2) % 10000;
		if (!bVisited[convertN]) {
			bVisited[convertN] = true;
			qInfo.push(make_pair(convertN, cmd + "D"));
		}

		convertN = num - 1 < 0 ? 9999 : num - 1;
		if (!bVisited[convertN]) {
			bVisited[convertN] = true;
			qInfo.push(make_pair(convertN, cmd + "S"));
		}

		convertN = (num % 1000) * 10 + num / 1000;
		if (!bVisited[convertN]) {
			bVisited[convertN] = true;
			qInfo.push(make_pair(convertN, cmd + "L"));
		}

		convertN = (num % 10) * 1000 + num / 10;
		if (!bVisited[convertN]) {
			bVisited[convertN] = true;
			qInfo.push(make_pair(convertN, cmd + "R"));
		}
	}

}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int nTestCase;
	cin >> nTestCase;

	for (int i = 0; i < nTestCase; ++i)
	{
		memset(bVisited, false, sizeof(bVisited));
		
		int nPreviousN, nGoal;
		cin >> nPreviousN >> nGoal;
		
		bfs(nPreviousN, nGoal);
	}
}