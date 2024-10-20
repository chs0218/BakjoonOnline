#include <iostream>
using namespace std;
/*
다이나믹 프로그래밍
비트마스킹
비트필드를 이용한 다이나믹 프로그래밍
*/
int N;
constexpr long long MOD = 1000000000;
long long stair[10][101][1024];
int main()
{
	cin >> N;
	for (int i = 1; i <= 9; ++i)
		stair[i][1][1 << i] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 1024; ++k)
			{
				if (j == 0) {
					stair[j][i][1 << j | k] += stair[j + 1][i - 1][k];
					stair[j][i][1 << j | k] %= MOD;
				}
				else if (j == 9) {
					stair[j][i][1 << j | k] += stair[j - 1][i - 1][k];
					stair[j][i][1 << j | k] %= MOD;
				}
				else {
					stair[j][i][1 << j | k] += stair[j - 1][i - 1][k];
					stair[j][i][1 << j | k] += stair[j + 1][i - 1][k];
					stair[j][i][1 << j | k] %= MOD;
				}
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; ++i)
	{
		ans += stair[i][N][1023];
		ans %= MOD;
	}
	cout << ans;
}