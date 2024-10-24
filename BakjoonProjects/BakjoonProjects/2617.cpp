#include <iostream>
using namespace std;
/*
플로이드 와샬
*/
int diff[100][100];

int main()
{
    int n, m;
    cin >> n >> m;

    // 초기화
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) diff[i][j] = 0;
            else diff[i][j] = 1e9;  // 큰 값으로 초기화
        }
    }

    // 입력 및 초기 관계 설정
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        diff[r][l] = 1;   // r이 l보다 무겁다
        diff[l][r] = -1;  // l이 r보다 가볍다
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (diff[i][k] != 1e9 && diff[k][j] != 1e9)
                {
                    if (diff[i][k] > 0 && diff[k][j] > 0)  // 둘 다 무거운 관계일 때
                        diff[i][j] = 1;
                    else if (diff[i][k] < 0 && diff[k][j] < 0)  // 둘 다 가벼운 관계일 때
                        diff[i][j] = -1;
                }
            }
        }
    }

    // 결과 계산
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int nHeavy = 0, nLight = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (diff[i][j] == 1)  // i가 j보다 무겁다
                ++nHeavy;
            else if (diff[i][j] == -1)  // i가 j보다 가볍다
                ++nLight;
        }
        if (nHeavy > (n - 1) / 2 || nLight > (n - 1) / 2)  // 중앙값을 초과하는 경우
            ++ans;
    }

    cout << ans << '\n';
}