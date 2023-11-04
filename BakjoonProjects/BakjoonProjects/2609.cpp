#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;

	int nMul = a * b;

	if (a < b) {
		int c = a;
		a = b;
		b = c;
	}

	while (b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}

	cout << a << "\n";
	cout << nMul / a;
}