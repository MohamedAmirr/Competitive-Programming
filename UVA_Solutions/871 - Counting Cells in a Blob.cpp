//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 2e3;
#define all(a)  a.begin(),a.end()
#define M_PI 3.14159265358979323846
#define endl '\n'
const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};

int n, m;

struct point {
    int x, y;
    bool vis = 0;

    point(int xx, int yy) {
        x = xx, y = yy;
    }
};

bool valid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m;
}


pair<int, int> st, en;
int arr[25][25];
int dis[25][25];
int mx;

int BFS(point src) {
    queue<point> q;
    q.push(src);
    int c = 0;
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int x = dx[i] + s.x;
            int y = dy[i] + s.y;
            if (valid(x, y)) {
                if (dis[x][y] > dis[s.x][s.y] + 1 and arr[x][y]) {
                    dis[x][y] = dis[s.x][s.y] + 1;
                    mx = max(mx, dis[x][y]);
                    q.push(point(x, y));
                    c++;
                }
            }
        }

    }
    return c + 1;
}


int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    while (T--) {
        string s;
        int u = 0;
        mx = 0;
        while (++u) {
            getline(cin, s);
            if (s.empty() and u == 1)getline(cin, s);
            else if (s.empty())break;
            for (int i = 0; i < s.size(); ++i) {
                arr[u - 1][i] = s[i] - '0';
            }
            m = s.size();
        }
        n = u - 1;
        for (int i = 0; i < 25; ++i) {
            for (int j = 0; j < 25; ++j) {
                dis[i][j] = 1e9;
            }
        }
        for (int i = 0; i < u - 1; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] and dis[i][j] == 1e9) {
                    dis[i][j] = 0;
                    mx = max(mx, BFS(point(i, j)));
                }
            }
        }
        cout << mx << endl;
        if (T)cout << endl;
    }

}