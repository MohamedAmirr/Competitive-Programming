// http://www.spoj.com/problems/RMQSQ/

#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
const int OO = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
const ll N = 1e5;
#define all(a)  a.begin(),a.end()
#define endl '\n'
//#define int long long

class SparseTable {
    // 0-Based implementation
    int n;
    int k;
    vector<vector<int>> dp;

public:
    SparseTable(int n, vector<int> &v) {
        this->n = n;
        k = __lg(n) + 1;
        dp.resize(k);
        for (int i = 0; i < k; ++i)
            dp[i].resize(n + 1);
        for (int i = 0; i < n; ++i)
            dp[0][i] = v[i];
    }

    int f(int first, int second) {
        return min(first, second);
    }

    void compute() {
        for (int i = 1; i < k; ++i)
            for (int j = 0; j + (1 << (i - 1)) < n; ++j)
                dp[i][j] = f(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
    }

    int cascadingQuery(int l, int r) {
        int ans = OO; // change value depending on 'f' function
        for (int p = __lg(r - l + 1); l <= r; p = __lg(r - l + 1)) {
            ans = f(ans, dp[p][l]);
            l += (1 << p);
        }
        return ans;
    }

    int query(int l, int r) {
        int len = r - l + 1;
        len = __lg(len);
        return f(dp[len][l], dp[len][r - (1 << len) + 1]);
    }

    ~SparseTable() {
        for (auto &s: dp)s.clear();
        dp.clear();
    }
};

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
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        int q;
        cin >> q;
        SparseTable hoba = SparseTable(n, v);
        hoba.compute();
        while (q--) {
            int a, b;
            cin >> a >> b;
            if (a > b)swap(a, b);
            cout << hoba.cascadingQuery(a, b) << endl;
        }
    }
//remember data type long long or int

}
