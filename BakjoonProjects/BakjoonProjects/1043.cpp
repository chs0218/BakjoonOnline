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

    // �θ� �ڱ��ڽ�����
    for (int i = 1; i <= nPeople; ++i)
        nParent[i] = i;

    int nKnowPeople;
    cin >> nKnowPeople;

    // ������ �ƴ� ����� 0�� �θ�
    for (int i = 0; i < nKnowPeople; ++i)
    {
        int n;
        cin >> n;
        nParent[n] = 0;
    }

    int arrNumPeople[50];
    // ��Ƽ Ƚ����ŭ ����
    for (int i = 0; i < nParty; ++i)
    {
        // ��Ƽ ���� �ο��� ��Ƽ �ο� �Է�
        cin >> arrNumPeople[i];
        cin >> arrParty[i][0];

        // �θ� ������Ʈ
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