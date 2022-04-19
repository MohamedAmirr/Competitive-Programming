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

struct Node {
    bool vis = 0;
    vector<Node *> neighbours = {};
};


bool valid(int x, int y) {
    return x >= 0 and x < 8 and y >= 0 and y < 8;
}


pair<int, int> st, en;
int arr[9][9];
int dis[9][9];

void BFS(point src) {
    queue<point> q;
    q.push(src);
    while (!q.empty()) {
        auto s = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int x = knightDx[i] + s.x;
            int y = knightDy[i] + s.y;
            if (valid(x, y)) {
                if (dis[x][y] > dis[s.x][s.y] + 1) {
                    dis[x][y] = dis[s.x][s.y] + 1;
                    q.push(point(x, y));
                }
            }
        }

    }
}


int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
//    cin >> T;
    while (T--) {
        char c;
        while (cin >> c) {
            st.first = (c - 'a');
            cin >> c;
            st.second = c - '0';
            cin >> c;
            en.first = (c - 'a');
            cin >> c;
            en.second = (c - '0');
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    dis[i][j] = 1e9;
                }
            }
            dis[st.first][st.second - 1] = 0;
            BFS(point(st.first, st.second - 1));
            cout << "To get from " << char(st.first + 'a') << st.second << " to " << char(en.first + 'a') << en.second
                 << " takes " << dis[en.first][en.second - 1] << " knight moves.\n";
        }
    }

}