#include <iostream>
#include <string>
using namespace std;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int nDigit, nLength;

	cin >> nDigit >> nLength;

	string str;
	cin >> str;

	int ans = 0;
	for (int i = 0; i < str.length() - (2 * nDigit); ++i) {
		if (str[i] == 'O') continue;
		else {
			int nCount = 0;
			for (int j = i + 1; j < str.length(); j+=2) {
				if (str[j] != 'O' || str[j + 1] != 'I') break;
				++nCount;

				if (nCount == nDigit) {
					++ans;
					--nCount;
				}

				i += 2;
			}
		}
	}

	cout << ans;
}