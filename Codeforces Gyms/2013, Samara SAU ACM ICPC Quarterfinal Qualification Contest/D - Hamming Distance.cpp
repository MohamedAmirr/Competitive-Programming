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
//remember data type long long or int
    while (T--) {
        int n;
        cin >> n;
        map<pair<int, char>, int> mp;
        for (int i = 0; i < 3; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); ++j) {
                mp[{j, s[j]}]++;
            }
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            ans += ' ';
        }
        for (auto &s: mp) {
            if (s.second == 3) {
                ans[s.first.first] = s.first.second;
            }
        }
        for (auto &s: mp) {
            if (s.second == 2 and (ans[s.first.first] == ' ')) {
                ans[s.first.first] = s.first.second;
            }
        }
        for (auto &s: mp) {
            if (s.second == 1 and (ans[s.first.first] == ' ')) {
                ans[s.first.first] = s.first.second;
            }
        }
        cout << ans << endl;

    }
//remember data type long long or int

}
