#include <iostream>
using namespace std;
/*
�÷��̵� �ͼ�
*/
int diff[100][100];

int main()
{
    int n, m;
    cin >> n >> m;

    // �ʱ�ȭ
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) diff[i][j] = 0;
            else diff[i][j] = 1e9;  // ū ������ �ʱ�ȭ
        }
    }

    // �Է� �� �ʱ� ���� ����
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        diff[r][l] = 1;   // r�� l���� ���̴�
        diff[l][r] = -1;  // l�� r���� ������
    }

    // �÷��̵�-���� �˰���
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (diff[i][k] != 1e9 && diff[k][j] != 1e9)
                {
                    if (diff[i][k] > 0 && diff[k][j] > 0)  // �� �� ���ſ� ������ ��
                        diff[i][j] = 1;
                    else if (diff[i][k] < 0 && diff[k][j] < 0)  // �� �� ������ ������ ��
                        diff[i][j] = -1;
                }
            }
        }
    }

    // ��� ���
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int nHeavy = 0, nLight = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (diff[i][j] == 1)  // i�� j���� ���̴�
                ++nHeavy;
            else if (diff[i][j] == -1)  // i�� j���� ������
                ++nLight;
        }
        if (nHeavy > (n - 1) / 2 || nLight > (n - 1) / 2)  // �߾Ӱ��� �ʰ��ϴ� ���
            ++ans;
    }

    cout << ans << '\n';
}