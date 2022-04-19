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
    int init, goal;
    vector<Node *> Children;
//    Node(int i) {
//        id = i;
//    }
};

bool ch;

void dfs(Node *node) {
    node->vis = 1;
    for (auto &child: node->Children) {
        if (child->id == node->id) {
            ch = true;
            return;
        }
        if (!child->vis) {
            child->id = !node->id;
            dfs(child);
            if (ch)return;
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
        int n, m;
        while (cin >> n) {
            ch = 0;
            if (!n)return 0;
            else
                cin >> m;
            vector<Node *> gr(n);
            for (auto &s: gr) {
                s = new Node;
            }
            for (int i = 0; i < m; ++i) {
                int a, b;
                cin >> a >> b;
                gr[a]->Children.push_back(gr[b]);
                gr[b]->Children.push_back(gr[a]);
            }
            gr[0]->id = 0;
            dfs(gr[0]);
            if (ch) {
                cout << "NOT BICOLORABLE.\n";
            } else cout << "BICOLORABLE.\n";
        }
    }
}