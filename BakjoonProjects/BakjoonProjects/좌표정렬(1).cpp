#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int num = 4;
	vector<pair<int, int>> v_Coord = { {1, 2}, {4, 2}, {3, 2}, {4, 4}, {3, 1} };

	sort(v_Coord.begin(), v_Coord.end(), less<pair<int, int>>());
	sort(v_Coord.begin(), v_Coord.end(), greater<pair<int, int>>());

	for (const pair<int, int>& coord : v_Coord)
		cout << coord.first << " " << coord.second << "\n";
}