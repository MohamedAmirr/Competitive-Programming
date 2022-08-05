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

set<string> s;

void combinations(string a, int ones, int begin = 0) {
    if (!ones) {
        s.insert(a);
        return;
    }
    for (int i = begin; i < a.size(); ++i) {
        if (a[i] == '0') {
            a[i] = '1';
            combinations(a, ones - 1, i + 1);
            a[i] = '0';
        }
    }
}

ll power(ll x, ll y) {
    if (y == 0) { return 1; }
    ll sq = power(x, y / 2);
    sq = ((sq) * (sq));
    if (y & 1)sq *= x;
    return sq;
}

ll conv(string &ss) {
    ll sum = 0;
    for (int i = 0; i < ss.size(); ++i) {
        sum += (ss[i] - '0') * power(2, i);
    }
    return sum;
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
    vector<ll> arr = {2, 3, 5, 7, 11, 13, 17};
    string aa;
    for (int i = 0; i < 17; ++i) {
        aa += '0';
    }
    for (int i = 0; i < arr.size(); ++i) {
        combinations(aa, arr[i]);
    }
    set<ll> final;
    for (auto ss: s)
        final.insert(conv(ss));
    map<ll, ll> mp;
    int i = 0;
    for (auto &ss: final) {
        mp[ss] = ++i;
    }
    mp[0] = 0;

//remember data type long long or int
    while (T--) {
        ll a, b;
        cin >> a >> b;
        auto it = mp.lower_bound(a);
        if (it != mp.begin())
            --it;
        auto it1 = --mp.upper_bound(b);
        cout << it1->second - (it->second) << endl;
    }
//remember data type long long or int

}
