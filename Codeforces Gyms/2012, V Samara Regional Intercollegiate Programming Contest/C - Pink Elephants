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


long long power(long long x, int y, int p) {
    long long res = 1;

    x = x % p;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long modInverse(long long n, int p) {
    return power(n, p - 2, p);
}

long long nCrModPFermat(long long n, int r, int p) {
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

long long fac[205];

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
        ll n, m;
        fac[0] = 1;
        cin >> n >> m;
        for (int i = 1; i <= 205; i++)
            fac[i] = (fac[i - 1] * i) % MOD;
        if (n == m)cout << 1 << endl;
        else if (n > m)cout << 0 << endl;
        else if (m - n == 1 or n == 1)cout << m << endl;
        else {
            cout << nCrModPFermat(m, n, MOD) << endl;
        }
    }
//remember data type long long or int

}
