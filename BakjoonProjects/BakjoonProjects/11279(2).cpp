/*
널리 잘 알려진 자료구조 중 최대 힙이 있다. 최대 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.
배열에 자연수 x를 넣는다.
배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.
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