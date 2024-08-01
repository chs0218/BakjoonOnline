#include <iostream>
#include <queue>
using namespace std;
int FruitNum[10];
int main()
{
	int N;
	cin >> N;

	queue<int> Tanghuru;
	int Ans = 0, TypesNum = 0;
	for (int i = 0; i < N; ++i)
	{
		int Fruit;
		cin >> Fruit;
		Tanghuru.push(Fruit);

		if (FruitNum[Fruit]++ == 0)
		{
			TypesNum += 1;
		}

		while (TypesNum > 2)
		{
			int FrontFruit = Tanghuru.front();
			Tanghuru.pop();

			if (--FruitNum[FrontFruit] == 0)
				TypesNum -= 1;
		}

		Ans = max(Ans, static_cast<int>(Tanghuru.size()));
	}
	cout << Ans;
}