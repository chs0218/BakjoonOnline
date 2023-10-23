#include <iostream>
#include <algorithm>
#include <string>
#include <array>
using namespace std;
array<int, 26> nCount;
int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
		++nCount[static_cast<int>(toupper(str[i]) - 'A')];

	auto it1 = max_element(nCount.begin(), nCount.end());
	auto it2 = max_element(it1 + 1, nCount.end());

	if (*it1 == *it2)
		cout << "?" << endl;
	else
		cout << static_cast<char>('A' + (it1 - nCount.begin())) << endl;
}