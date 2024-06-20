#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int SLength, ELength;
	string S, E;

	cin >> SLength >> ELength >> S >> E;

	while (1)
	{
		string UpperS = S, UpperE = E;
		transform(UpperS.begin(), UpperS.end(), UpperS.begin(), [](unsigned char c) { return toupper(c); });
		transform(UpperE.begin(), UpperE.end(), UpperE.begin(), [](unsigned char c) { return toupper(c); });

		auto Size = UpperE.find(UpperS);
		if (Size == string::npos)
			break;

		E.erase(E.begin() + Size, E.begin() + Size + SLength);
	}

	if (E.length() == 0) cout << "EMPTY";
	else cout << E;

	return 0;
}