//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const int OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const ll N = 1e2;
#define all(a)  a.begin(),a.end()
#define M_PI 3.14159265358979323846
#define endl '\n'
const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};
//#define int long long


signed main() {
    besmellah
// لا تحسبن المجد تمرا انت اكله لن تبلغ المجد حتي تلعق الصبر ❤
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
#endif
    int T = 1;
    //cin >> T;
//remember data type long long or int
    while (T--) {
        ll a, b;
        ll a1, b1;
        ll a2, b2;
        cin >> a >> b;
        cin >> a1 >> b1;
        cin >> a2 >> b2;
        if ((a1 + a2 <= a and max(b1, b2) <= b) or
            (a1 + b2 <= a and max(a2 , b1) <= b) or
            (b1 + b2 <= a and max(a2 , a1) <= b) or
            (a2 + b1 <= a and max(a1 , b2) <= b) or
            (a1 + a2 <= b and max(b1 , b2) <= a) or
            (a1 + b2 <= b and max(a2 , b1) <= a) or
            (b1 + b2 <= b and max(a2 , a1) <= a) or
            (a2 + b1 <= b and max(a1 , b2) <= a)) {
            cout << "YES\n";
        } else cout << "NO\n";

    }
//remember data type long long or int

}
