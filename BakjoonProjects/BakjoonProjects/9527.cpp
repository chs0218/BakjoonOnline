#include <iostream>
using namespace std;
long long dp[55];
long long GetTotal(long long n)
{
	long long ret = 0;
	for (int i = 55; i >= 0; --i)
	{
		if (n & (1LL << i)) {
			ret += dp[i - 1];
			ret += n - (1LL << i) + 1;
			n -= (1LL << i);
		}
	}
	return ret;
}
int main()
{
	dp[0] = 1;

	for (int i = 1; i < 55; ++i)
		dp[i] = dp[i - 1] * 2 + (1LL << i);

	long long A, B;
	cin >> A >> B;
	cout << GetTotal(B) - GetTotal(A - 1);
}