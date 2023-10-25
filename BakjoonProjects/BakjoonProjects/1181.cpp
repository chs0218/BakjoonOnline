#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> vWords(n);
    for (int i = 0; i < n; ++i)
        cin >> vWords[i];

    sort(vWords.begin(), vWords.end(), [](string& str1, string& str2) {
        if (str1.size() == str2.size())
            return str1 < str2;
        return str1.size() < str2.size();
        });

    vWords.erase(unique(vWords.begin(), vWords.end()), vWords.end());

    for (const string& str : vWords)
        cout << str << "\n";
}