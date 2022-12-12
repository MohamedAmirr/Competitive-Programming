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
    cin >> T;
//remember data type long long or int
    while (T--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        map<char, set<int>> mp;
        for (int i = 0; i < s.size(); ++i) {
//            if (s[i] > '0') {
            mp[s[i]].insert(i);
//            }
        }
        int sum = 0;
        for (int i = 0; i < s.size() and k; ++i) {
            char j = '0';
            if (i == 0)j = '1';
            for (; j < s[i]; ++j) {
                auto it = mp[j].upper_bound(i + sum);
                if (it != mp[j].end()) {
                    int u = *it - sum;
                    if (u - i <= k and u - i > 0) {
                        for (int l = i; l < u; ++l) {
                            mp[s[l]].erase(l);
                        }
                        s.erase(s.begin() + i, s.begin() + u);
                        sum += (u - i);
                        k -= (u - i);
                        i--;
                    }
                }
            }
        }
        while (k--) {
            s.pop_back();
        }
        cout << s << endl;
    }
//remember data type long long or int

}
