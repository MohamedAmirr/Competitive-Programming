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
        int k;
        cin >> k;
        string s;
        cin >> s;
        s = ' ' + s;
        int j = 1;
        map<char, int> occ;
        vector<int> ans(s.size() + 1);
        int c = 0;
        for (int i = 1; i <= s.size(); ++i) {
            occ[s[i]]++;
            if (occ[s[i]] == 1)c++;
            if (c < k) {
                ans[i] = -1;
                continue;
            }
            while (c > k and j < i) {
                occ[s[j]]--;
                if (!occ[s[j]])c--;
                j++;
            }
            while (occ[s[j]] > 1 and ans[j - 1] == -1) {
                occ[s[j]]--;
                j++;
            }
            if (ans[j - 1] == -1) {
                ans[i] = -1;
            } else {
                ans[i] = ans[j - 1] + 1;
            }
        }
        for (int i = 1; i < ans.size() - 1; ++i) {
            cout << ans[i] << ' ';
        }
    }
//remember data type long long or int

}
