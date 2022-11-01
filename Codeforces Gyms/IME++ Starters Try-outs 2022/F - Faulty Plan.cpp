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

vector<vector<vector<int>>> dp(81, vector<vector<int>>(805, vector<int>(805, -1)));
int n;
vector<pair<int, int>> v;

int solve(int i, int l, int r) {
    if (i >= n)return 0;
    if ((l * 3) >= 50 or (r * 3) >= 50 or (r + l) * 3 >= 90) {
        return 0;
    }
    int &ret = dp[i][l][r];
    if (~ret)return ret;
    int op1 = ((l + v[i].first) * 3 < 50 and (r + v[i].second) * 3 < 50 and
               (l + r + v[i].first + v[i].second) * 3 < 90) ? solve(i + 1, l + v[i].first, r + v[i].second) + 1 : 0;
    int op2 = (i + 1 < n) ? solve(i + 1, l, r) : 0;
    return ret = max({ret, op1, op2});
}

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
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            int s;
            cin >> s >> v[i].first >> v[i].second;
        }
        cout << 80 - (n - solve(0, 0, 0)) << endl;

    }
//remember data type long long or int

}
