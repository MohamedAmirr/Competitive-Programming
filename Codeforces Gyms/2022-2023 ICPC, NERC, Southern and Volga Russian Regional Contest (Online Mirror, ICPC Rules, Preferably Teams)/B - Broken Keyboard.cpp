#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool flag = true;
        bool click = true;
        for (int i = 0; i < s.size(); i++) {
            if (click) {
                click = false;
            } else {
                if (i == s.size() - 1 or s[i] != s[i + 1])
                    flag = false;
                click = true;
                i++;
            }
        }
        cout << ((flag) ? "YES" : "NO") << endl;
    }
}
