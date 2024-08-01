#include <iostream>
#include <string>
using namespace std;
void FizzBuzz(int N)
{
	if (N % 3 == 0 && N % 5 == 0) cout << "FizzBuzz\n";
	else if (N % 3 == 0) cout << "Fizz\n";
	else if (N % 5 == 0) cout << "Buzz\n";
	else cout << N << "\n";
}

int main()
{
	string Str[3];
	cin >> Str[0] >> Str[1] >> Str[2];

	for (int i = 0; i < 3; ++i)
	{
		if (isdigit(Str[i][0]))
		{
			int Cur = stoi(Str[i]);
			int AnsNum = Cur + (3 - i);

			FizzBuzz(AnsNum);
			break;
		}
	}
}