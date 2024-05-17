#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string input;
    cin >> input;

    string ans;
    ans.resize(input.size());
    fill(ans.begin(), ans.end(), 'z');

    for (int i = 0; i < input.size() - 2; ++i)
    {
        for (int j = i + 1; j < input.size() - 1; ++j)
        {
            string firstWord = string{ input.begin(), input.begin() + i + 1 };
            string secondWord = string{ input.begin() + i + 1, input.begin() + j + 1 };
            string thirdWord = string{ input.begin() + j + 1, input.end() };

            reverse(firstWord.begin(), firstWord.end());
            reverse(secondWord.begin(), secondWord.end());
            reverse(thirdWord.begin(), thirdWord.end());

            string curWord;
            curWord += firstWord;
            curWord += secondWord;
            curWord += thirdWord;

            if (ans > curWord)
            {
                ans = curWord;
            }
        }
    }

    cout << ans;
}