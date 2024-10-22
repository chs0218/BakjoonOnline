#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int nWords = 0;
pair<string, int> dictionary[50];
int main() {
    string str;
    while (1)
    {
        getline(cin, str);
        stringstream ss(str);
        if (str == "end") break;

        string word;
        while (ss >> word)
        {
            bool bIsInDict = false;
            for (int i = 0; i < nWords; ++i)
            {
                if (dictionary[i].first == word)
                {
                    bIsInDict = true;
                    dictionary[i].second += 1;
                    break;
                }
            }

            if (!bIsInDict)
            {
                dictionary[nWords].first = word;
                dictionary[nWords].second = 1;
                ++nWords;
            }
        }

        for (int i = 0; i < nWords; ++i)
        {
            cout << dictionary[i].first << " : " << dictionary[i].second << "\n";
        }
    }
    return 0;
}