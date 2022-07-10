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

signed main() {
    besmellah
//Sky is the limit ❤
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
    //cin >> T;
//remember data type long long or int
    while (T--) {
        int n;
        cin >> n;
        vector<int> prefix(n + 1);
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        sort(all(a));
        sort(all(b));
        for (int i = 1; i <= n; ++i) {
            prefix[i] += prefix[i - 1] + a[i - 1];
        }
        int total = 0;
        int mn = -1;
        for (int i = 0; i < b.size(); ++i) {
            int idx = upper_bound(all(a), b[i]) - a.begin();
            int sum = b[i] * ((idx) - i) + (prefix.back() - prefix[idx]);
            if (total < sum) {
                total = max(total, sum);
                mn = b[i];
            }
        }
        cout << mn << ' ';
        cout << total << endl;
    }
//remember data type long long or int

}
