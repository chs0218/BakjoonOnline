#include <iostream>
#include <unordered_map>
using namespace std;
/*
자료 구조
이분 탐색
누적 합
해시를 사용한 집합과 맵
*/
long long T;
int N, M;
long long A[1001];
long long B[1001];
unordered_map<long long, long long> uMapA;
void Input()
{
	long long n = 0;

	cin >> T >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> n;
		A[i] = A[i - 1] + n;
	}
	cin >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> n;
		B[i] = B[i - 1] + n;
	}
}
int Solve()
{
	long long ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j)
		{
			long long sumA = A[i] - A[j];
			if (uMapA.insert(make_pair(sumA, 0)).second == false) uMapA.at(sumA) += 1;
			else uMapA[sumA] = 1;
		}
	}

	for (int i = 1; i <= M; ++i) {
		for (int j = 0; j < i; ++j)
		{
			long long sumB = B[i] - B[j];
			if (uMapA[T - sumB]) ans += uMapA[T - sumB];
		}
	}

	cout << ans;
	return 0;
}
int main()
{
	Input();
	Solve();
}