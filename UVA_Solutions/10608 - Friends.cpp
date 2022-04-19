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
const ll N = 1e5;
#define all(a)  a.begin(),a.end()
#define M_PI 3.14159265358979323846
#define endl '\n'
const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};

struct Node {
    int id = -1;
    bool vis = 0;
    vector<Node *> Children;
};
int c;

void dfs(Node *node) {
    c++;
    node->vis = 1;
    for (auto &child: node->Children) {
        if (!child->vis) {
            dfs(child);
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
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<Node *> graph(n);
        for (auto &g: graph) {
            g = new Node;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            graph[a]->Children.push_back(graph[b]);
            graph[b]->Children.push_back(graph[a]);
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if (!graph[i]->vis) {
                dfs(graph[i]);
                mx = max(mx, c);
                c = 0;
            }
        }
        cout << mx << endl;
    }
}