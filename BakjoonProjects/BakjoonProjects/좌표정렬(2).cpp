#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int num;
	cin >> num;

	vector<pair<int, int>> v_Coord;
	for (int i = 0; i < num; ++i)
	{
		int x, y;
		cin >> x >> y;
		v_Coord.push_back({ x, y });
	}

	sort(v_Coord.begin(), v_Coord.end());

	for (const pair<int, int>& coord : v_Coord)
		cout << coord.first << " " << coord.second << "\n";
}