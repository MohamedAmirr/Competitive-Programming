#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

int n,grid[205][205];
map<pair<pair<int, int>, vector<vector<bool>>>, int> dp;

int go(int i, int j, vector<vector<bool>> vis) {
    if (i == n - 1 and j == n - 1)
        return grid[i][j];
    if (dp.find({{i, j}, vis}) != dp.end())
        return dp[{{i, j}, vis}];
    int op1 = 0, op2 = 0, op3 = 0, op4 = 0;
    auto vis1 = vis;
    if (i + 1 < n and !vis1[i + 1][j]) {
        vis1[i][j] = true;
        op1 = grid[i][j] + go(i + 1, j, vis1);
    }
    auto vis2 = vis;
    if (j + 1 < n and !vis2[i][j + 1]) {
        vis2[i][j] = true;
        op2 = grid[i][j] + go(i, j + 1, vis2);
    }
    auto vis3 = vis;
    if (i == n - 1 and !vis3[0][j]) {
        vis3[i][j] = true;
        op3 = grid[i][j] + go(0, j, vis3);
    }
    auto vis4 = vis;
    if (j == n - 1 and !vis4[i][0]) {
        vis4[i][j] = true;
        op4 = grid[i][j] + go(i, 0, vis4);
    }
    return dp[{{i, j}, vis}] = max({op1, op2, op3, op4});
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    int sum(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            sum += grid[i][j];
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans, sum - grid[n - i - 1][i]);
//            cout << grid[n-i-1][i] << " ";
    }
    cout << ans << endl;
}
