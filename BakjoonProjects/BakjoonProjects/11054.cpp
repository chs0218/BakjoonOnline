#include <iostream>
#include <vector>
using namespace std;
/*
다이나믹 프로그래밍
*/
int plusArr[1000];
int minusArr[1000];
int main()
{
    int arrNum;
    cin >> arrNum;

    vector<int> arr(arrNum);
    for (int i = 0; i < arrNum; ++i)
        cin >> arr[i];

    for (int i = 0; i < arrNum; ++i)
    {
        plusArr[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i] && plusArr[i] < plusArr[j] + 1)
                plusArr[i] = plusArr[j] + 1;
        }
    }

    for (int i = arrNum - 1; i >= 0; --i)
    {
        minusArr[i] = 1;
        for (int j = arrNum - 1; j >= 0; --j)
        {
            if (arr[j] < arr[i] && minusArr[i] < minusArr[j] + 1)
                minusArr[i] = minusArr[j] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < arrNum; ++i)
        ans = max(ans, plusArr[i] + minusArr[i] - 1);
    cout << ans;
}