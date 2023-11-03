#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
struct Document {
    int nPriority;
    int nSeq;
};
int arrPriority[10];
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int nCase;
    cin >> nCase;

    for (int i = 0; i < nCase; ++i)
    {
        int nDocument, nTarget;
        cin >> nDocument >> nTarget;

        queue<Document> vDocument;
        memset(arrPriority, 0, sizeof(arrPriority));

        for (int j = 0; j < nDocument; ++j)
        {
            int nPriority;
            cin >> nPriority;
            ++arrPriority[nPriority];
            vDocument.push(Document{ nPriority, j });
        }

        int ans = 1;
        while (1) {
            Document doc = vDocument.front();
            vDocument.pop();

            int nPrirority = doc.nPriority;

            bool bPrint = true;
            for (int j = nPrirority + 1; j <= 9; ++j) {
                if (arrPriority[j]) {
                    bPrint = false;
                    break;
                }
            }

            if (bPrint) {
                if (doc.nSeq == nTarget) {
                    cout << ans << "\n";
                    break;
                }

                --arrPriority[nPrirority];
                ++ans;
            }

            else {
                vDocument.push(doc);
            }
        }
    }
}