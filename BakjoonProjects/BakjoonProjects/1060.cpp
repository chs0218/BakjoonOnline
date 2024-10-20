#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int S[50];
int main()
{
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	int L;
	cin >> L;

	// 집합 S에 포함된 정수들은 좋은 구간이 0이다.
	for (int i = 0; i < L; ++i)
	{
		cin >> S[i];
		pq.push({ 0, S[i] });
	}

	int N;
	cin >> N;

	sort(S, &S[L]);

	for (int i = 0; i < L; ++i)
	{
		int Start = 0;
		i == 0 ? Start = 1 : Start = S[i - 1] + 1;

		int End = S[i] - 1;

		if (Start == End && i == 0)
		{
			pq.push({ 0, Start });
			continue;
		}

		int Count = 0;
		for (int j = Start; j <= (Start + End) / 2; ++j)
		{
			if (Count == 50) break;

			long long Value = static_cast<long long>(j - Start + 1) * static_cast<long long>(End - j + 1) - static_cast<long long>(1);
			
			pq.push({ Value, j });

			if (j != End - Count)
			{
				pq.push({ Value, End - Count });
			}

			Count += 1;
		}
	}

	int nPrint = 0;
	while (N-- > 0)
	{
		if (!pq.empty())
		{
			pair<long long, int> Cur = pq.top();
			pq.pop();

			cout << Cur.second << " ";
		}

		else
		{
			++nPrint;
			cout << S[L - 1] + nPrint << " ";
		}
	}
}