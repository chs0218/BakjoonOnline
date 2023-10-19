/*
�θ� �� �˷��� �ڷᱸ�� �� �ִ� ���� �ִ�. �ִ� ���� �̿��Ͽ� ������ ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�迭�� �ڿ��� x�� �ִ´�.
�迭���� ���� ū ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.
���α׷��� ó���� ����ִ� �迭���� �����ϰ� �ȴ�.
*/

#include <iostream>
#include <set>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    multiset<int> stNum;
    int nSize;
    cin >> nSize;

    for (int i = 0; i < nSize; ++i)
    {
        int n;
        cin >> n;
        if (n)
            stNum.insert(n);
        else
        {
            if (stNum.empty())
                cout << "0\n";
            else
            {
                int nNum = *(stNum.rbegin());
                cout << nNum << "\n";
                int nErased = stNum.erase(nNum);
                for (int i = 0; i < nErased - 1; ++i)
                    stNum.insert(nNum);
            }
        }
    }