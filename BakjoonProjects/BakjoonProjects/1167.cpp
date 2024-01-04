#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
vector <pair<int, int>> vec[100001];
bool visited[100001];
int V = 0, ans = 0, nLastNode = 0;

void dfs(int current, int sum) {
	if (sum > ans) {
		nLastNode = current;
		ans = sum;
	}

	for (int i = 0; i < vec[current].size(); i++) {
		int num = vec[current][i].first;
		if (visited[num] == 0) {
			visited[num] = 1;
			dfs(num, sum + vec[current][i].second);
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> V;
	for (int i = 1; i <= V; i++) { 
		int t = 0;
		cin >> t;
		int v = 0, w = 0;
		while (1) {
			cin >> v;
			if (v == -1)
				break;
			cin >> w;
			vec[t].push_back(make_pair(v, w));
		}
	}

	visited[1] = 1;
	dfs(1, 0);

	ans = 0;
	memset(visited, 0, sizeof(visited));

	visited[nLastNode] = 1;
	dfs(nLastNode, 0);

	cout << ans << endl;
	return 0;
}