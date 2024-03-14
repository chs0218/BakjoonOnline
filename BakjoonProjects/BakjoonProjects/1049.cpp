#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    
    int MinPackage = 1e10, MinIndividual = 1e10;
    for (int i = 0; i < M; ++i)
    {
        int PackagePrice, IndividualPrice;
        cin >> PackagePrice >> IndividualPrice;
        MinPackage = min(MinPackage, PackagePrice);
        MinIndividual = min(MinIndividual, IndividualPrice);
    }

    int ans = 1e10;

    if (MinPackage >= MinIndividual * 6)
        ans = N * MinIndividual;
    else
    {
        int CaseA = (N / 6) * MinPackage + (N % 6) * MinIndividual;
        int CaseB = (N % 6 == 0) ? (N / 6) * MinPackage : (N / 6 + 1) * MinPackage;
        ans = min(CaseA, CaseB);
    }
    cout << ans;
}