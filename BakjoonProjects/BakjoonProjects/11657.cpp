#include <iostream>
#include <vector>
using namespace std;
struct Edge {
	int s, e, t;
};
void BellManFord(int n, vector<Edge> edges)
{
	// ���� ����� ��ü ������ ������ ����ŭ ������ ������, 
	// ���� ����Ŭ�� ������ �ִ� ���̰� 6õ���̶�� 
	// �� ������ �ٽ� N�� �ݺ��ϸ鼭 N�� ���� �͸�ŭ ������ Ű��� �ȴ�.
	// ��, int�� ǥ�� �Ұ����� ���ڰ� ����.

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