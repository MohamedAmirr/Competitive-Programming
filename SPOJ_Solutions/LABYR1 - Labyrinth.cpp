#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e3;
#define M_PI 3.14159265358979323846
#define endl '\n'
int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};


int n, m;
char arr[N + 5][N + 5];
int vis[N + 5][N + 5];

bool valid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m and arr[x][y] != '#';
}

int mx;
int id;
int xx, yy;

void dfs(int x, int y, int len) {
    vis[x][y] = id;
    if (len > mx) {
        mx = max(len, mx);
        xx = x;
        yy = y;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny) and vis[nx][ny] != id) {
            dfs(nx, ny, len + 1);
        }
    }
}

int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //    freopen("closing.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        xx = 0, yy = 0;
        id = 0;
        mx = 0;
        int dotx, doty;
        bool check = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                vis[i][j] = 0;
                if (arr[i][j] == '.' and !check) {
                    dotx = i, doty = j;
                    check = true;
                }
            }
        }
        id++;
//        dfs twice to get a max length
        dfs(dotx, doty, 0);
        id++;
        mx = 0;
        dfs(xx, yy, 0);
        cout << "Maximum rope length is " << mx << '.' << endl;
    }
}
