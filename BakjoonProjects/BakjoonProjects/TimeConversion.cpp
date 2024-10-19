#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;

    string hourStr = string{ s.begin(), s.begin() + 2 };
    string leftStr = string(s.begin() + 2, s.end() - 2);
    string timeFormat = string{ s.end() - 2, s.end() };

    int nHour = stoi(hourStr);
    if (timeFormat == "AM" && nHour == 12) nHour -= 12;
    if (timeFormat == "PM" && nHour != 12) nHour += 12;
    cout << nHour << leftStr;
}