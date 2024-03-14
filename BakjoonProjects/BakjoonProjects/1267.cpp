#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int CostY = 0, CostM = 0;
    for (int i = 0; i < N; ++i)
    {
        int CallTime;
        cin >> CallTime;

        CostY += 10 + (CallTime / 30) * 10;
        CostM += 15 + (CallTime / 60) * 15;
    }

    if (CostY == CostM) cout << "Y M " << CostY;
    else if(CostY < CostM) cout << "Y " << CostY;
    else cout << "M " << CostM;
}