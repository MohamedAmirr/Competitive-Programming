#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

const int N = 3005, OO = 0x3f3f3f3f3f3f3f3f, MOD = 1e9 + 7;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) cin >> i;
    sort(v.begin(), v.end());
    if (v.back() - v[0] < v[0] + v[1] - 1) {
        cout << "YES" << endl << v.back() - v[0] + 1;
    } else {
        cout << "NO" << endl;
    }
}
