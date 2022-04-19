//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e7;
#define all(a)  a.begin(),a.end()
#define M_PI 3.14159265358979323846
#define endl '\n'
const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};

long long ncr(long long n, long long k) {
    long long a = 1;
    for (int i = 1; i <= k; i++) {
        a = a * (n - i + 1);
        a = a / i;
    }
    return a;
}


ll nCr(int n, int r) {
    long long p = 1, k = 1;
    if (n < r)return 0;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;

            long long m = __gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    } else
        p = 1;
    return p;
}

int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
//    cin >> T;
    while (T--) {
        
    }
}