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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int dx[] = {-1, +1, +0, +0};
    int dy[] = {+0, +0, -1, +1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    bool flag = true;
    auto valid = [&](int x, int y) {
        return (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] != '#');
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '#') {
                int ans(0);
                for (int k = 0; k < 4; k++) {
                    int x = dx[k] + i;
                    int y = dy[k] + j;
                    if (valid(x, y)) ans++;
                }
                if (ans >= 3){
                    cout << "YES" << endl;
                    return 0;
                }
                if(ans <= 1){
                    flag= false;
                }
            }
        }
    }
    cout << ((flag) ? "YES" : "NO") << endl;

}
