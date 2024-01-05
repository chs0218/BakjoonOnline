#include <iostream>
using namespace std;
int MyPow(int A, int B, int C)
{
	if (B == 0) return 1;
	if (B == 1) return A % C;
	long long temp = MyPow(A, B / 2, C);
	if (B % 2 == 0) return (temp * temp) % C;
	else return (temp * temp % C) * A % C;
}
int main()
{
	long long A, B, C;
	cin >> A >> B >> C;

	cout << MyPow(A, B, C);
}