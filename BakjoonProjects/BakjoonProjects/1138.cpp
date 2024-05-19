#include <iostream>
#include <vector>
using namespace std;
int N;
int main()
{
    cin >> N;
    vector<int> vAns(N);

    for (int i = 0; i < N; ++i)
        vAns[i] = 11;

    for (int i = 1; i <= N; ++i)
    {
        int curNum = 0;
        int LeftNum = 0;
        cin >> LeftNum;

        while (LeftNum != 0)
        {
            if (vAns[curNum++] > i)
            {
                --LeftNum;
            }
        }

        while (vAns[curNum] != 11)
        {
            ++curNum;
        }
        vAns[curNum] = i;
    }

    for (int i = 0; i < N; ++i)
        cout << vAns[i] << " ";
}