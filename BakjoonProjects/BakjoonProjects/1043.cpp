#include <iostream>
using namespace std;
int nParent[51];
int arrParty[50][50];
int GetParent(int n)
{
    if (nParent[n] != n)
        nParent[n] = GetParent(nParent[n]);
    return nParent[n];
}
void Merge(int a, int b)
{
    int p1 = GetParent(a);
    int p2 = GetParent(b);

    if (p1 == p2)
        return;

    if (p1 < p2)
        nParent[p2] = p1;
    else
        nParent[p1] = p2;
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nPeople, nParty;
    cin >> nPeople >> nParty;

    // 부모를 자기자신으로
    for (int i = 1; i <= nPeople; ++i)
        nParent[i] = i;

    int nKnowPeople;
    cin >> nKnowPeople;

    // 진실을 아는 사람은 0이 부모
    for (int i = 0; i < nKnowPeople; ++i)
    {
        int n;
        cin >> n;
        nParent[n] = 0;
    }

    int arrNumPeople[50];
    // 파티 횟수만큼 루프
    for (int i = 0; i < nParty; ++i)
    {
        // 파티 참여 인원과 파티 인원 입력
        cin >> arrNumPeople[i];
        cin >> arrParty[i][0];

        // 부모를 업데이트
        for (int j = 1; j < arrNumPeople[i]; ++j)
        {
            cin >> arrParty[i][j];
            Merge(arrParty[i][0], arrParty[i][j]);
        }
    }

    int ans = nParty;
    for (int i = 0; i < nParty; ++i)
    {
        for (int j = 0; j < arrNumPeople[i]; ++j)
        {
            if (GetParent(arrParty[i][j]) == 0)
            {
                --ans;
                break;
            }
        }
    }
    cout << ans;
}