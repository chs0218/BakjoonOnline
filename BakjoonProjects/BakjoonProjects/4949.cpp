#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	while (1) {
		getline(cin, str);
		if (str == ".") break;

		stack<char> stkChar;

		bool bBalance = true;
		for (const char& c : str)
		{
			if (c == '(' || c == '[')
				stkChar.push(c);

			else if (c == ')' || c == ']')
			{
				if (stkChar.empty())
				{
					bBalance = false;
					break;
				}

				char chk = stkChar.top();

				if ((c == ')' && chk == '[') ||
					(c == ']' && chk == '('))
				{
					bBalance = false;
					break;
				}

				stkChar.pop();
			}
		}

		if (stkChar.empty() && bBalance) cout << "yes\n";
		else cout << "no\n";
	}
}