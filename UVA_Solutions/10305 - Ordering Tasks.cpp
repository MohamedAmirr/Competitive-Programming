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

    Node(int i) {
        id = i;
    }
};

queue<int> ss;

void dfs(Node *node, vector<int> &ans) {
    node->vis = 1;
    ss.push(node->id);
    for (auto &child: node->Children) {
        if (!child->vis) {
            dfs(child, ans);
        }
    }
    ans.push_back(node->id);
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
        int n, m;
        while (cin >> n >> m and (n or m)) {
            vector<Node *> gr(n);
            int ID = 0;
            for (auto &g: gr) {
                g = new Node(++ID);
            }
            for (int i = 0; i < m; ++i) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                gr[v]->Children.push_back(gr[u]);
            }
            vector<int> ans;
            for (int i = 0; i < n; ++i) {
                if (!gr[i]->vis) {
                    dfs(gr[i], ans);
                }
            }
            cout << ans.front();
            for (int i = 1; i < ans.size(); ++i) {
                cout << ' ' << ans[i];
            }

            cout << endl;
        }
    }
}