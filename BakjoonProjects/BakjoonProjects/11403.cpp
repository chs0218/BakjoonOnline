#include <iostream>
#
using namespace std;
bool bNode[100][100];
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nNode;
    cin >> nNode;

    for (int i = 0; i < nNode; ++i)
    {
        for (int j = 0; j < nNode; ++j)
            cin >> bNode[i][j];
    }

    for (int k = 0; k < nNode; ++k)
    {
        for (int i = 0; i < nNode; ++i)
        {
            for (int j = 0; j < nNode; ++j)
            {
                if (bNode[i][k] && bNode[k][j])
                    bNode[i][j] = true;
            }
        }
    }

    for (int i = 0; i < nNode; ++i)
    {
        for (int j = 0; j < nNode; ++j)
            cout << bNode[i][j] << " ";
        cout << "\n";
    }
}