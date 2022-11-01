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
    /*
     * lw taleb montawy byro7 3la a5r sf fy korsy gamb el shebak fady
     * lw msh montawy byro7 l a5r saf yshof ay korsy fady w lw l2a gmb el tor2a byo3od 3ltol
     */
//remember data type long long or int
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<pair<bool, bool>> rght(n, {0, 0}), lft(n, {0, 0});
        ll ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'I') {
                bool done = 0;
                for (int j = n - 1; j >= 0; --j) {
                    if (!rght[j].second) {
                        rght[j].second = 1;
                        done = 1;
                        ans += (j * 2) + 10;
                        break;
                    } else if (!lft[j].first) {
                        lft[j].first = 1;
                        done = 1;
                        ans += (j * 2) + 10;
                        break;
                    }
                }
                if (!done) {
                    for (int j = n - 1; j >= 0; --j) {
                        if (!rght[j].first) {
                            rght[j].first = 1;
                            ans += (j * 2) + 5;
                            break;
                        } else if (!lft[j].second) {
                            lft[j].second = 1;
                            ans += (j * 2) + 5;
                            break;
                        }
                    }
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    if (!rght[j].second) {
                        rght[j].second = 1;
                        ans += (j * 2) + 10;
                        break;
                    } else if (!lft[j].first) {
                        lft[j].first = 1;
                        ans += (j * 2) + 10;
                        break;
                    } else {
                        if (rght[j].second and !rght[j].first) {
                            rght[j].first = 1;
                            ans += (j * 2) + 5;
                            break;
                        } else if (lft[j].first and !lft[j].second) {
                            lft[j].second = 1;
                            ans += (j * 2) + 5;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
//remember data type long long or int

}
