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
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                int a;
                cin >> a;
                v.push_back({a, i});
            }
        }
        sort(all(v));
        map<int, int> done;
        map<int, int> ans;
        set<int> s;
        multiset<int> ms;
        for (int i = 0; i < v.size(); ++i) {
            if (done[v[i].second]) {
                int c = ms.count(v[i].second + 1);
//                c--;
                ms.erase(v[i].second + 1);
                if (ms.size() == ((n - 1) * 2))
                    ans[v[i].second] = 1;
                while (c--)ms.insert(v[i].second + 1);
//                ms.insert(v[i].second+1)
            } else {
                s.erase(v[i].second + 1);
                if (s.size() == (n - 1)) {
                    done[v[i].second] = 1;
                }
            }
            s.insert(v[i].second + 1);
            ms.insert(v[i].second + 1);
            if (ms.count(v[i].second + 1) > 2) {
                ms.erase(v[i].second + 1);
                int c = 2;
                while (c--)ms.insert(v[i].second + 1);
            }
        }
        cout << ans.size() << endl;
        for (auto &s: ans) {
            if (s.second)cout << s.first + 1 << ' ';
        }
    }
//remember data type long long or int

}
