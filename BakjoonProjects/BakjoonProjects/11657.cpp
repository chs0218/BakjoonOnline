#include <iostream>
#include <vector>
using namespace std;
struct Edge {
	int s, e, t;
};
void BellManFord(int n, vector<Edge> edges)
{
	// 벨만 포드는 전체 과정을 정점의 수만큼 돌리기 때문에, 
	// 음수 사이클의 절댓값의 최대 길이가 6천만이라면 
	// 그 과정을 다시 N번 반복하면서 N을 곱한 것만큼 절댓값을 키우게 된다.
	// 즉, int로 표현 불가능한 숫자가 있음.

	vector<long long> dist(n + 1, 1e9);

	dist[1] = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < edges.size(); ++j)
		{
			int s = edges[j].s;
			int e = edges[j].e;
			int t = edges[j].t;

			if (dist[s] != 1e9 && dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
			}
		}
	}

	for (int i = 0; i < edges.size(); ++i)
	{
		int s = edges[i].s;
		int e = edges[i].e;
		int t = edges[i].t;

		if (dist[s] != 1e9 && dist[e] > dist[s] + t) {
			cout << "-1\n";
			return;
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if (dist[i] == 1e9) cout << "-1\n";
		else cout << dist[i] << "\n";
	}
}
int main()
{
	int N, M;
	cin >> N >> M;

	vector<Edge> vEdge(M);

	for (int i = 0; i < M; ++i)
		cin >> vEdge[i].s >> vEdge[i].e >> vEdge[i].t;

	BellManFord(N, vEdge);
}