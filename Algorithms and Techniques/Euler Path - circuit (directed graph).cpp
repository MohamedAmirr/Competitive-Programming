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
const ll MOD = 1e18 + 7;
const ll N = 5e2;
#define all(a)  a.begin(),a.end()
#define M_PI 3.14159265358979323846
#define endl '\n'
const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};
//#define int long long

struct Node {
    int id = -1;
    int outdeg = 0;
    int indeg = 0;
    vector<Node *> neighbours;

    Node(int ID) : id(ID) {};
};

void dfs(Node *node, vector<int> &path) {
    while (node->outdeg) {
        auto neighbour = node->neighbours[--node->outdeg];
        dfs(neighbour, path);
    }
    path.push_back(node->id);
}

vector<int> Euler(vector<Node *> &nodes, int edges) {
    int st = 0, en = 0;
    for (auto &s: nodes) {
        if (s->outdeg - s->indeg > 1)return {};
        else if (s->outdeg - s->indeg == 1)st++;
        else if (s->indeg - s->outdeg == 1)en++;
    }

    if (!((!st and !en) or (st == 1 and en == 1)))return {};

    vector<int> path;
    for (auto &node: nodes) {
        if ((!st and node->outdeg > 0) or (st == 1 and node->outdeg - node->indeg == 1)) {
            dfs(node, path);
            break;
        }
    }


    if (path.size() != edges + 1)
        return {};
    reverse(all(path));
    return path;
}


signed main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
//    cin >>T;
//remember data type long long or int
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<Node *> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node(i + 1);
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            nodes[u]->outdeg++;
            nodes[v]->indeg++;
            nodes[u]->neighbours.push_back(nodes[v]);
        }
        auto path = Euler(nodes, m);
        
    }
//remember data type long long or int

}
