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
    vector<int> a(n), b(n);
    for (auto &i: a) cin >> i;
    for (auto &i: b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ansa(0), ansb(0);
    int j = 0;
    for (int i = 0; i < n and j < n; i++) {
        if (a[i] > b[j]) {
            ansa++;
            j++;
        }
    }
    j = 0;
    for (int i = 0; i < n and j < n; i++) {
        if (a[j] < b[i]) {
            ansb++;
            j++;
        }
    }
    if (ansa * 2 > n and ansb * 2 > n) {
        cout << "Both" << endl;
    } else if (ansa * 2 <= n and ansb * 2 <= n) {
        cout << "None" << endl;
    } else if (ansa * 2 > n and ansb * 2 <= n) {
        cout << "First" << endl;
    } else if (ansa * 2 <= n and ansb * 2 > n) {
        cout << "Second" << endl;
    }

}
