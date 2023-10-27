#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int nSubject = 0;
    cin >> nSubject;

    float nTotalScore = 0;
    int nMaxScore = 0;

    for (int i = 0; i < nSubject; ++i)
    {
        int nScore;
        cin >> nScore;

        nTotalScore += nScore;

        if (nMaxScore < nScore)
            nMaxScore = nScore;
    }


    cout << nTotalScore / static_cast<float>(nMaxScore)
        / static_cast<float>(nSubject) * 100.0f;
}