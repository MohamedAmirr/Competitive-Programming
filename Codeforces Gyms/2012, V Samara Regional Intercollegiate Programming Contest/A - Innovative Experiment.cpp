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
#define int long long

bool prime[100005];
vector<int> pr;

void SieveOfEratosthenes() {
    int n = 100000;
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
            pr.push_back(p);
        }
    }
}

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
        ll n;
        SieveOfEratosthenes();
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            cout << 1 << endl;
            continue;
        }
        vector<int> hoba;
        int sum = 0;
        for (int i = 2; i <= 100000; ++i) {
            int s = i;
            if (!prime[s])continue;
            int u = 1;
            while (n % s == 0) {
                n /= s;
                u *= s;
            }
            if (u > 1) {
                sum += u;
                hoba.push_back(u);
            }
            if (n == 1)break;
        }
        if ((n > 1) or sum > 100000) {
            cout << "No solution\n";
            continue;
        }
        int pos = 1;
        cout << sum << endl;
        for (auto &s: hoba) {
            int hobaTnia = pos;
            for (int i = 1; i < s; ++i) {
                cout << ++pos << ' ';
            }
            pos++;
            cout << hobaTnia << ' ';
        }
    }
//remember data type long long or int

}
