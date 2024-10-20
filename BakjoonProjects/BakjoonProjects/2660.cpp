#include <iostream>
#include <vector>
using namespace std;
/*
그래프 이론
그래프 탐색
너비 우선 탐색
최단 경로
플로이드-워셜
*/
int vScore[51][51];
int main()
{
    for (int i = 1; i <= 50; ++i)
        for (int j = 1; j <= 50; ++j)
            (i == j) ? vScore[i][j] = 0 : vScore[i][j] = 1e9;

    int N;
    cin >> N;
    while (1)
    {
        int l, r;
        cin >> l >> r;

        if (l == -1) break;

        vScore[l][r] = 1;
        vScore[r][l] = 1;
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                vScore[i][j] = min(vScore[i][j], vScore[i][k] + vScore[k][j]);
            }
        }
    }

    int ansScore = 1e9;
    vector<int> vAns;

    for (int i = 1; i <= N; ++i)
    {
        int score = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (score < vScore[i][j])
                score = vScore[i][j];
        }

        if (score < ansScore)
        {
            ansScore = score;
            vAns.clear();
        }

        if (score == ansScore)
        {
            vAns.push_back(i);
        }
    }

    cout << ansScore << " " << vAns.size() << "\n";
    for (const int& ans : vAns)
        cout << ans << " ";
}