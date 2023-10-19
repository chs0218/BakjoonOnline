/*
�θ� �� �˷��� �ڷᱸ�� �� �ִ� ���� �ִ�. �ִ� ���� �̿��Ͽ� ������ ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�迭�� �ڿ��� x�� �ִ´�.
�迭���� ���� ū ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.
���α׷��� ó���� ����ִ� �迭���� �����ϰ� �ȴ�.
*/

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    priority_queue<int> qNum;
    int nSize;
    cin >> nSize;

    for (int i = 0; i < nSize; ++i)
    {
        int n;
        cin >> n;
        if (n)
            qNum.push(n);
        else
        {
            if (qNum.empty())
                cout << "0\n";
            else
            {
                cout << qNum.top() << "\n";
                qNum.pop();
            }
        }
    }
}