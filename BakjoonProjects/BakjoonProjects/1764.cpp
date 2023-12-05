#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nList, nInput;
    cin >> nList >> nInput;

    unordered_set<string> ustNames;
    vector<string> vNames;
    for (int i = 0; i < nList; ++i)
    {
        string str;
        cin >> str;

        ustNames.insert(str);
    }

    for (int i = 0; i < nInput; ++i)
    {
        string str;
        cin >> str;
        if (ustNames.find(str) != ustNames.end()) vNames.push_back(str);
    }

    sort(vNames.begin(), vNames.end());

    cout << vNames.size() << "\n";
    for (const string& str : vNames)
        cout << str << "\n";
}