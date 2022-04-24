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

ll egcd(ll a, ll b, ll &x, ll &y) { /// ax + by = gcd(a,b)
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = egcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}

ll modInverse(ll a, ll m) { /// (a/b)%m = ((a%m)*(modInverse(b)%m))%m
    ll x, y, g;
    g = egcd(a, m, x, y);
    if (g > 1)
        return -1;
    return (x + m) % m;
}

ll pushB(ll h1, ll h2, ll xp, ll p) { // xp = x^(lenToPush(h2))
    return ((h1 * xp) % p + h2) % p;
}

ll pushF(ll h1, ll h2, ll xp, ll p) { // xp = x^(mainLen(h1))
    return (h1 + (h2 * xp) % p) % p;
}

ll popF(ll h1, ll h2, ll xp, ll p) { // xp = x^(mainLen(h1)- lenToPop(h2))
    return (h1 - ((h2 * xp) % p) + p) % p;
}

ll popB(ll h1, ll h2, ll xp, ll p) {  // xp = x^(LenToPop(h2))
    return ((((h1 - h2) + p) % p) * modInverse(xp, p) % p) % p;
}

ll get(int l, int r, vector<ll> &H, ll xp, ll p) {
    return l > 0 ? popF(H[r], H[l - 1], xp, p) : H[r];
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
    ll x = 128;
    vector<ll> xp1(1e5 + 1), xp2(1e5 + 1);
    xp1[0] = 1;
    xp2[0] = 1;
    ll p1 = 1e9 + 7, p2 = 1e9 + 9;
    for (int i = 1; i <= 1e5; i++) {
        xp1[i] = (x * xp1[i - 1]) % p1;
        xp2[i] = (x * xp2[i - 1]) % p2;
    }
//remember data type long long or int
    while (T--) {
        int n, k;
        while (cin >> n) {
            string s, s1;
            cin >> s >> s1;
            if (s.size() > s1.size()) {
                cout << '\n';
                continue;
            }
            k = s.size();
            vector<ll> h1(s1.size());
            h1[0] = s1[0];
            for (int i = 1; i < s1.size(); ++i) {
                h1[i] = pushB(h1[i - 1], s1[i], x, p1);
            }
            ll hh = 0;
            for (int i = 0; i < s.size(); ++i) {
                hh = pushB(hh, s[i], x, p1);
            }
            vector<int> ans;
            for (int i = 0; i + k - 1 < s1.size(); ++i) {
                int l = i, r = i + k - 1;
                ll hh1 = get(l, r, h1, xp1[k], p1);
//            ll hh2 = get(l, r, h2, xp2[k], p2);
                if (hh == hh1) {
                    ans.push_back(i);
                }
            }
            for (auto &s: ans)cout << s << endl;
        }
    }
//remember data type long long or int

}
