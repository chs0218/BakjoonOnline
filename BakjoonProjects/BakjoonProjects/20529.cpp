#include <iostream>
using namespace std;
char mbti[10'0000][4];
int calDistance(int i, int j, int k) {
    int distance = 0;

    if (mbti[i][0] != mbti[j][0]) ++distance;
    if (mbti[i][1] != mbti[j][1]) ++distance;
    if (mbti[i][2] != mbti[j][2]) ++distance;
    if (mbti[i][3] != mbti[j][3]) ++distance;

    if (mbti[i][0] != mbti[k][0]) ++distance;
    if (mbti[i][1] != mbti[k][1]) ++distance;
    if (mbti[i][2] != mbti[k][2]) ++distance;
    if (mbti[i][3] != mbti[k][3]) ++distance;

    if (mbti[j][0] != mbti[k][0]) ++distance;
    if (mbti[j][1] != mbti[k][1]) ++distance;
    if (mbti[j][2] != mbti[k][2]) ++distance;
    if (mbti[j][3] != mbti[k][3]) ++distance;

    return distance;
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nTestCase;
    cin >> nTestCase;

    for (int t = 0; t < nTestCase; ++t)
    {
        int nStudent;
        cin >> nStudent;


        for (int i = 0; i < nStudent; ++i)
            cin >> mbti[i];

        if (nStudent > 32) cout << "0\n";
        else {
            int ans = 1e10;

            for (int i = 0; i < nStudent - 2; ++i)
                for (int j = i + 1; j < nStudent - 1; ++j)
                    for (int k = j + 1; k < nStudent; ++k)
                        ans = min(ans, calDistance(i, j, k));

            cout << ans << "\n";
        }
    }
}