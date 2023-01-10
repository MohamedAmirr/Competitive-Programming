#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

signed main() {
    besmellah
//Sky is the limit ❤
#ifdef CLION
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
#endif
    int T = 1;
    //cin >> T;
//remember data type long long or int
    while (T--) {
        int n;
        cin >> n;
        cout << min(15, 3000 / n + (3000 % n > 0));
    }
//remember data type long long or int

}
