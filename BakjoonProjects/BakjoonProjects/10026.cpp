#include <iostream>
#include <memory.h>
#include <string>
#include <queue>
using namespace std;
char gridRG[100][100];
char gridNormal[100][100];
struct Info {
    int i;
    int j;
    char c;
};
int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nGrid;
    cin >> nGrid;

    for (int i = 0; i < nGrid; ++i)
    {
        string strInput;
        cin >> strInput;

        for (int j = 0; j < nGrid; ++j)
        {
            gridRG[i][j] = strInput[j];
            gridNormal[i][j] = strInput[j];
        }
    }

    int nSection = 0, nRGSection = 0;
    for (int i = 0; i < nGrid; ++i)
    {
        for (int j = 0; j < nGrid; ++j)
        {
            if (gridNormal[i][j] != '\0')
            {
                char rgb = gridNormal[i][j];

                ++nSection;
                gridNormal[i][j] = '\0';

                queue<Info> qInfo;
                qInfo.push(Info{ i, j, rgb });

                while (!qInfo.empty()) {
                    Info info = qInfo.front();
                    qInfo.pop();

                    for (int k = 0; k < 4; ++k)
                    {
                        int ni = info.i + di[k];
                        int nj = info.j + dj[k];

                        if (ni < 0 || ni >= nGrid ||
                            nj < 0 || nj >= nGrid)
                            continue;

                        if (gridNormal[ni][nj] == info.c) {
                            gridNormal[ni][nj] = '\0';
                            qInfo.push(Info{ ni, nj, info.c });
                        }
                    }
                }
            }

            if (gridRG[i][j] != '\0')
            {
                char rgb = gridRG[i][j];

                ++nRGSection;
                gridRG[i][j] = '\0';

                queue<Info> qInfo;
                qInfo.push(Info{ i, j, rgb });

                while (!qInfo.empty()) {
                    Info info = qInfo.front();
                    qInfo.pop();

                    for (int k = 0; k < 4; ++k)
                    {
                        int ni = info.i + di[k];
                        int nj = info.j + dj[k];

                        if (ni < 0 || ni >= nGrid ||
                            nj < 0 || nj >= nGrid)
                            continue;

                        if (info.c == 'R' || info.c == 'G') {
                            if (gridRG[ni][nj] == 'R' || gridRG[ni][nj] == 'G') {
                                gridRG[ni][nj] = '\0';
                                qInfo.push(Info{ ni, nj, info.c });
                            }
                        }

                        else {
                            if (gridRG[ni][nj] == info.c) {
                                gridRG[ni][nj] = '\0';
                                qInfo.push(Info{ ni, nj, info.c });
                            }
                        }
                    }
                }
            }
        }
    }

    cout << nSection << " " << nRGSection;
}