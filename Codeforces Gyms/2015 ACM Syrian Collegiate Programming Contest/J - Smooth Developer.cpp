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


vector<vector<int>> G;
vector<bool> vis;

void dfs(int n) {
    vis[n] = 1;
    for (auto &it: G[n]) {
        if (!vis[it])
            dfs(it);
    }
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
    cin >> T;
//remember data type long long or int
    while (T--) {
        int n, m;
        cin >> n >> m;
        G = vector<vector<int>>(n);
        vis = vector<bool>(n);
        map<string, int> en;
        vector<string> de(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            en[s] = i;
            de[i] = s;
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                cin >> s;
                G[i].push_back(en[s]);
            }
        }
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            if (!vis[en[s]]) {
                dfs(en[s]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                cout << de[i] << '\n';
            }
        }
    }
//remember data type long long or int

}
