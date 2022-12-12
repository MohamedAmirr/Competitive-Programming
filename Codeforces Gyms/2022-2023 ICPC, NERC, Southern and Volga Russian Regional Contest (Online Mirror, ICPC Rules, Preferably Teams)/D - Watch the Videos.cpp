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
    int n, m;
    cin >> n >> m;
    queue<int> q;
    multiset<int, greater<>> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    int cur = m;
    int ans(0);
    while (!st.empty()) {
        auto u = *st.begin();
        st.erase(st.begin());
        ans += u;
        if(!q.empty()) {
            cur += q.front();
            q.pop();
        }
        q.push(u);
        cur -= u;
        auto lb = st.lower_bound(cur);
        if (lb != st.end()) {
            ans += *lb;
            q.pop();
            cur += u;
            q.push(*lb);
            cur -= *lb;
            st.erase(lb);
        } else {
            ans++;
            q.pop();
            cur += u;
        }
    }
    cout << ans + q.size() << endl;
}
