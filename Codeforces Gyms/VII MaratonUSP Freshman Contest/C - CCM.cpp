//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

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

double x, y, vCris, vMarcel;
double disBetweenCarlMa;

bool needMoreSpeed(double vCarl) {
    double sum = vCris + vCarl, radCarl = x * (vCarl / sum), radCr = x * (vCris / sum);
    if (radCarl < radCr)return 1;
    double radMa = disBetweenCarlMa - radCarl;
    if (radCarl < radMa)return 1;
    return 0;
}

double BS() {
    double l = 0, r = 1e18 + 1;
    for (int i = 0; i < 400; ++i) {
        double mid = (l + r) / 2.0;
        if (needMoreSpeed(mid))l = mid;
        else r = mid;
    }
    return l;
}

ll power(ll x, ll y) {
    if (y == 0) { return 1; }
    ll sq = power(x, y / 2);
    sq = ((sq % MOD) * (sq % MOD)) % MOD;
    if (y & 1)sq *= x;
    return sq % MOD;
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
    //cin >> T;
//remember data type long long or int
    while (T--) {
        cin >> x >> y;
        cin >> vCris >> vMarcel;
        disBetweenCarlMa = sqrt(pow(x / 2, 2) + pow(y, 2));
        cout << fixed << setprecision(6);
        cout << BS() << endl;
    }
//remember data type long long or int

}
