#include <iostream>
#include <string>
using namespace std;
int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int FirstAns = A + B - C;
    cout << FirstAns << endl;

    string StringA = to_string(A);
    StringA.append(to_string(B));

    int ConvertedAB = stoi(StringA);
    int SecondAns = ConvertedAB - C;
    cout << SecondAns << endl;
}