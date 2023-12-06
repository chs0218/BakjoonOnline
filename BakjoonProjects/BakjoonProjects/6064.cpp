#include <iostream>
using namespace std;
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int nCase;
    cin >> nCase;
    
    for(int i = 0; i < nCase; ++i){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        
        int span = 0;
        int tx = 0, ty = 0;
        int ans = 0;

        if (m > n) {
            span = n;
            tx = ty = ans = y;
        }
        else {
            span = m;
            tx = ty = ans = x;
        }

        while(1){
            if (tx == x && ty == y) {
                cout << ans << "\n";
                break;
            }

            if (tx == m && ty == n) {
                cout << "-1\n";
                break;
            }

            tx += span;
            while (tx > m) tx -= m;

            ty += span;
            while (ty > n) ty -= n;

            ans += span;

            if (tx == ty) {
                cout << "-1\n";
                break;
            }
        }
    }
}