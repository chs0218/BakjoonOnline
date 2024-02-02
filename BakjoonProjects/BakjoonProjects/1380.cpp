#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
int main()
{
    int tmp = 1;
    while (1) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<string> vName(n);

        cin.ignore();
        for (int i = 0; i < n; ++i)
            getline(cin, vName[i]);

        unordered_set<int> uSet;
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            int num;
            char tmp;
            cin >> num >> tmp;

            if(uSet.empty()) uSet.insert(num);
            else {
                auto it = uSet.find(num);

                if(it != uSet.end()) uSet.erase(num);
                else uSet.insert(num); 
            }
        }
        cout << tmp++ << " " << vName[(*uSet.begin() - 1)] << "\n";
    }
}