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
#define all(a)  a.begin(),a.end()
#define M_PI 3.14159265358979323846
#define endl '\n'
const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};
//#define int long long



char arr[51][51];
int vis[51][51];
int n, m, id;

bool valid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m;
}


void dfs(int i, int j) {
    vis[i][j] = id;
    for (int l = 0; l < 4; l++) {
        int x = i + dx[l], y = j + dy[l];
        if (valid(x, y) and vis[x][y] != id and arr[i][j] != '#') {
            dfs(x, y);
        }
    }
}


bool check() {
    bool ch = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ch and arr[i][j] == '.' and vis[i][j] != id) {
                return 1;
            }
            if (vis[i][j] != id and arr[i][j] == '.') {
                dfs(i, j);
                ch = 1;
            }
        }
    }
    return 0;
}


signed main() {
    besmellah
// لا تحسبن المجد تمرا انت اكله لن تبلغ المجد حتي تلعق الصبر ❤
#ifndef ONLINE_JUDGE
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
        vector<pair<int, int>> que;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] == '?') {
                    que.push_back({i, j});
                }
            }
        }
        id++;
        if (check()) {
            cout << "Impossible\n";
            return 0;
        }
        id++;
        int c = 0;
        for (int i = 0; i < que.size(); ++i) {
            arr[que[i].first][que[i].second] = '#';
            if (!check()) {
                arr[que[i].first][que[i].second] = '.';
                id++;
                c++;
                if (!check())c++;
                else arr[que[i].first][que[i].second] = '#';
            } else {
                arr[que[i].first][que[i].second] = '?';
//                c++;
            }
            if (c > 1) {
                cout << "Ambiguous\n";
                break;
            }
            c = 0;
            id++;
        }
        if (c <= 1) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (arr[i][j] == '?') {
                        arr[i][j] = '.';
                    }
                    cout << arr[i][j];
                }
                cout << endl;
            }
        }

    }
//remember data type long long or int

}
