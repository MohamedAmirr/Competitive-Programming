#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int OO = 0x3f3f3f3f;
#define endl '\n'

const int dx[] = {+1, -1, +0, +0, +1, -1, +1, -1};
const int dy[] = {+0, +0, +1, -1, +1, -1, -1, +1};

map<pair<pair<int, int>, int>, int> dp;
int n, m;
vector<vector<int>> v(101, vector<int>(101)), vis(101, vector<int>(101));
pair<int, int> st, en;


bool valid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

int solve(int i, int j, int taken, int ans) {
    if (i == en.first and j == en.second) {
        return ans;
    }
    int &ret = dp[{{i, j}, taken}];
    if (ret)return ret;

    int op1 = OO;

    for (int k = 0; k < 4; ++k) {

        int xx = i + dx[k];
        int yy = j + dy[k];

        if (valid(xx, yy) and !vis[xx][yy]) {
            // before mark stamp as taken, save the previous state of it, so when return from dp call assign it with previous val
            int tmpOfPrevStatOfStamp = !(taken & (1 << v[xx][yy]));
            taken |= (1 << v[xx][yy]);
            
            vis[xx][yy] = 1;
            op1 = min(op1, solve(xx, yy, taken, ans + tmpOfPrevStatOfStamp));
            vis[xx][yy] = 0;
            if (tmpOfPrevStatOfStamp) {
                int tmp = ((1 << v[xx][yy]) & taken);
                taken ^= (tmp);
            } else {
                int tmp = !((1 << v[xx][yy]) & taken);
                taken ^= (tmp);
            }
        }
    }

    return ret = op1;
}

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
        cin >> n >> m;
        cin >> st.first >> st.second >> en.first >> en.second;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> v[i][j];
            }
        }
        st.first--;st.second--;
        en.first--;en.second--;
        int taken = 0;
        taken |= (1 << v[st.first][st.second]);
        taken |= (1 << v[en.first][en.second]);
        vis[st.first][st.second] = 1;
        cout << solve(st.first, st.second, taken, 1 + (v[st.first][st.second] != v[en.first][en.second])) << endl;
    }
//remember data type long long or int

}
