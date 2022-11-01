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
        string s;
        cin >> s;
        vector<int> hoba;
        int ans = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'F') {
                hoba.push_back(i);
            } else {
                if (hoba.empty()) {
                    ans = 0;
                    break;
                }
                hoba.pop_back();
            }
        }
        if (ans) {
            int c = 0;
            for (int i = 0; i < hoba.size(); ++i) {
                if (hoba[i] == i)c++;
                else break;
            }
            cout << c << endl;
        } else {
            cout << "I cry\n";
        }
    }
//remember data type long long or int

}
