/*
���� �켱���� ť(dual priority queue)�� �������� �켱���� ťó�� �����͸� ����, ������ �� �ִ� �ڷ� �����̴�. 
�������� ť���� �������� �����͸� ������ �� ����(operation) ��ɿ� ���� �켱������ ���� ���� ������ �Ǵ� ���� ���� ������ �� �ϳ��� �����ϴ� ���̴�. 
���� �켱���� ť�� ���ؼ� �� ���� ������ ���Ǵµ�, �ϳ��� �����͸� �����ϴ� �����̰� �ٸ� �ϳ��� �����͸� �����ϴ� �����̴�. 
�����͸� �����ϴ� ������ �� �� ������ ���еǴµ� �ϳ��� �켱������ ���� ���� ���� �����ϱ� ���� ���̰� �ٸ� �ϳ��� �켱������ ���� ���� ���� �����ϱ� ���� ���̴�.
������ �����ϴ� ���� �켱���� ť Q�� �ִٰ� ��������. Q�� ����� �� ������ �� ��ü�� �켱������� ��������.
Q�� ����� �Ϸ��� ������ �־��� �� �̸� ó���� �� ���������� Q�� ����� ������ �� �ִ񰪰� �ּڰ��� ����ϴ� ���α׷��� �ۼ��϶�.
*/

#include <iostream>
#include <set>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    multiset<int> stNums;
    int nTestCase;
    cin >> nTestCase;

    for (int i = 0; i < nTestCase; ++i)
    {
        int nCommands;
        cin >> nCommands;
        for (int j = 0; j < nCommands; ++j)
        {
            char cCommand;
            int nNum;
            cin >> cCommand >> nNum;
            if (cCommand == 'I')
                stNums.insert(nNum);
            else
            {
                if (stNums.empty())
                    continue;

                int nTarget = 0;

                if (nNum == 1)
                    nTarget = *stNums.rbegin();
                else
                    nTarget = *stNums.begin();

                int nEraseCount = stNums.erase(nTarget);
                for (int k = 0; k < nEraseCount - 1; ++k)
                    stNums.insert(nTarget);
            }
        }

        if (stNums.empty())
            cout << "EMPTY\n";
        else
            cout << *stNums.rbegin() << " " << *stNums.begin() << "\n";

        stNums.clear();
    }
}