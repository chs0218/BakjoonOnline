#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int N;
	vector<int> Liquid(N);
	for (int i = 0; i < N; ++i)
		cin >> Liquid[i];

	sort(Liquid.begin(), Liquid.end());

	int Left = 0;
	int Right = N - 1;

	int AnsLiquidIndex[2];
	int Ans = 1e9;

	while (Left < Right)
	{
		int Mid = (Left + Right) / 2;
		int Sum = Liquid[Left] + Liquid[Right];

		if (Ans > abs(Sum))
		{
			Ans = abs(Sum);
			AnsLiquidIndex[0] = Left;
			AnsLiquidIndex[1] = Right;
		}

		if (Sum < 0)
			Left++;
		else
			Right--;
	}
}