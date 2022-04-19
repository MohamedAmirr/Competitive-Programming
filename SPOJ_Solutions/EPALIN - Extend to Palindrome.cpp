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
#define int long long

vector<int> KMP(string s) {
    vector<int> prefix(s.size());
    prefix[0] = 0;
    int border = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (border > 0 and s[border] != s[i])border = prefix[border - 1];
        if (s[border] == s[i])border++;
        prefix[i] = border;
    }
    return prefix;
}

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
//    cin >> T;
//remember data type long long or int
    while (T--) {
        string s;
        while (cin >> s) {
            string str = s;
            reverse(all(str));
            auto v = KMP(str + "&" + s);
            cout << s + str.substr(*v.rbegin()) << endl;
        }
    }
//remember data type long long or int

}