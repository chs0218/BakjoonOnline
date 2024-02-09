#include <iostream>
using namespace std;
int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int minDistance = min(x, y);
    minDistance = min(minDistance, w - x);
    minDistance = min(minDistance, h - y);
    cout << minDistance;
}