//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const ll N = 1e5;
const double EPS = 1e-6;
#define M_PI 3.14159265358979323846
#define all(a)  a.begin(),a.end()
#define endl '\n'

int lg(int n) { return 31 - __builtin_clz(n); }

const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};
//#define int long long


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
        int x1, y1, x2, y2;
        vector<int> x(2), y(2);
        cin >> x[1 - 1] >> y[1 - 1] >> x[2 - 1] >> y[2 - 1];
        string s;
        cin >> s;
        string t;
        cin >> t;
        bool ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < 2; ++j) {
                char ch = (j == 0) ? s[i] : t[i];
                if (ch == 'U') {
                    y[j]++;
                } else if (ch == 'D') {
                    y[j]--;
                } else if (ch == 'R') {
                    x[j]++;
                } else if (ch == 'L') {
                    x[j]--;
                }
                if (x[0] == x[1] and y[0] == y[1]) {
                    cout << "Rodou!\n";
                    ans = 1;
                    break;
                }
            }
            if (ans)break;
        }
        if (!ans)cout << "Quase!\n";
    }
//remember data type long long or int

}
