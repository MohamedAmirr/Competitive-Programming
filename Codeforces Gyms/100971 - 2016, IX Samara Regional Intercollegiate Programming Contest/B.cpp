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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<pair<int, int>> ans;
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if (v[i] == i + 1) {
                if (pos != -1) {
                    swap(v[i], v[pos]);
                    ans.push_back({pos + 1, i + 1});
                    pos = -1;
                } else pos = i;
            }
        }
        if (pos != -1) {
            for (int i = 0; i < v.size(); ++i) {
                if (v[i] != pos + 1) {
                    swap(v[i], v[pos]);
                    ans.push_back({pos + 1, i + 1});
                    break;
                }
            }
        }
        cout << ans.size() << endl;
        for (auto &s: ans) {
            cout << s.first << ' ' << s.second << endl;
        }
    }
//remember data type long long or int

}
