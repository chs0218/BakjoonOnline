#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
bool bBoard[51][51];
bool bVisited[51][51];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> qNode;
	qNode.push(make_pair(x, y));

	bVisited[y][x] = true;

	while (!qNode.empty()) {
		pair<int, int> curNode = qNode.front();
		qNode.pop();

		int cx = curNode.first;
		int cy = curNode.second;

		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
		
			if (0 <= nx && 0 <= ny && nx < 51 && ny < 51)
			{
				if (bBoard[ny][nx] && !bVisited[ny][nx])
				{
					bVisited[ny][nx] = true;
					qNode.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void dfs(int x, int y)
{
	bVisited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && 0 <= ny && nx < 51 && ny < 51)
		{
			if (bBoard[ny][nx] && !bVisited[ny][nx])
				dfs(nx, ny);
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int nTestCase = 0;
	cin >> nTestCase;

	for (int nCase = 0; nCase < nTestCase; ++nCase)
	{
		memset(bBoard, false, sizeof(bBoard));
		memset(bVisited, false, sizeof(bVisited));

		int nWidth, nHeight, nCabbage;
		cin >> nWidth >> nHeight >> nCabbage;

		for (int i = 0; i < nCabbage; ++i)
		{
			int x, y;
			cin >> x >> y;
			bBoard[y][x] = true;
		}

		int ans = 0;
		for (int i = 0; i < nHeight; ++i)
		{
			for (int j = 0; j < nWidth; ++j)
			{
				if (bBoard[i][j] && !bVisited[i][j])
				{
					++ans;
					//dfs(j, i);
					bfs(j, i);
				}
			}
		}

		cout << ans << "\n";
	}
}