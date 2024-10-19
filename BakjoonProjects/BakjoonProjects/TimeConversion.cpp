#include <iostream>
#include <regex>
#include <string>
using namespace std;

string timeConversion1(string s) {
    string hourStr = string{ s.begin(), s.begin() + 2 };
    string leftStr = string(s.begin() + 2, s.end() - 2);
    string timeFormat = string{ s.end() - 2, s.end() };

    int nHour = stoi(hourStr);
    if (timeFormat == "AM" && nHour == 12) nHour -= 12;
    if (timeFormat == "PM" && nHour != 12) nHour += 12;

    string result = to_string(nHour) + leftStr;
    if (nHour < 10) result = "0" + result;
    return result;
}

string timeConversion2(string s) {
    regex timePattern(R"((\d{2}):(\d{2}):(\d{2})(AM|PM))");
    /*
    std::vector<std::string> phone_numbers = {"010-1234-5678", "010-123-4567",
                                            "011-1234-5567", "010-12345-6789",
                                            "123-4567-8901", "010-1234-567"};
    std::regex re("[01]{3}-\\d{3,4}-\\d{4}");
    for (const auto &number : phone_numbers) {
    std::cout << number << ": " << std::boolalpha
              << std::regex_match(number, re) << '\n';
    
    */
    smatch match;

    bool bMatch = regex_match(s, match, timePattern);
    if (false == bMatch)
    {
        return string{};
    }

    int nHour = stoi(match[0]);
    if (match[4] == "AM" && nHour == 12) nHour -= 12;
    if (match[4] == "PM" && nHour != 12) nHour += 12;

    string result = to_string(nHour) + ":" + match[2].str() + ":" + match[3].str();
    if (nHour < 10) result = "0" + result;
    return result;
}

int main()
{
    string s;
    cin >> s;

    cout << timeConversion2(s);
}