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
#define int long long

vector<int> v;
int n, p, q;


bool valid(ll mid) {
    vector<int> vec = v;
    int hoba = 0;
    for (int i = 0; i < vec.size(); ++i) {
        int hobaTnia = vec[i] - (q * mid);
        if (hobaTnia > 0) {
            hoba += (hobaTnia + p - q - 1) / (p - q);
        }
    }
    return hoba <= mid;

}

ll BS() {
    ll l = 0, r = 1e10, mid;
    ll ans = 1e10;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (valid(mid)) {
            r = mid - 1;
            ans = min(mid, ans);
        } else l = mid + 1;
    }
    return ans;
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
        cin >> n >> p >> q;
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        if (p == q) {
            int mx = *max_element(all(v));
            cout << mx / p + (mx % p > 0) << endl;
            continue;
        }
        sort(all(v));
        cout << BS() << endl;
    }
//remember data type long long or int

}
