# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(),x.end()

using namespace std;

void solve() {
    int n ; cin >> n ;
    for (int i = 2; i*i <= n; ++i) {
        if ( n % i == 0 ){
            cout << n/i << ' ' << (i-1)*(n/i) << '\n' ;
            return;
        }
    }
    cout << 1 << ' ' << n - 1 << '\n' ;
}

int main() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1; cin >> t ;
    while (t--)
        solve();
    return 0;
}
