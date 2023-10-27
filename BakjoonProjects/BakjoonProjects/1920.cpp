#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> m_Set;

    int nList = 0;
    cin >> nList;

    for (int i = 0; i < nList; ++i)
    {
        int n;
        cin >> n;

        m_Set.insert(n);
    }

    int nCase = 0;
    cin >> nCase;

    for (int i = 0; i < nCase; ++i)
    {
        int n;
        cin >> n;
        if (m_Set.find(n) != m_Set.end())
            cout << "1\n";
        else
            cout << "0\n";
    }
}