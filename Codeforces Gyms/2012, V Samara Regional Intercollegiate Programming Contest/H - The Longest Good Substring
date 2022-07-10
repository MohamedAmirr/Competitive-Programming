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
//#define int long long


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
        int k;
        cin >> k;
        string s;
        cin >> s;
        map<int, int> mp;
        int mx = 0;
        int sz = s.size();
        int c = 0;
        int l = 1, r = 1;
        for (int i = 0, j = i; i < s.size() and j < sz;) {
            while (i < sz and c >= k) {
                mp[s[i]]--;
                if (!mp[s[i]])c--;
                i++;
            }
            while (j < sz and c < k) {
                if (!mp[s[j]]) {
                    c++;
                }
                mp[s[j]]++;
                j++;
            }
            while (mp[s[j]])mp[s[j]]++, j++;
            if (mx < j - i) {
                mx = max(mx, j - i);
                l = i + 1, r = j;
            }
        }
        cout << l << ' ' << r << endl;
    }
//remember data type long long or int

}
