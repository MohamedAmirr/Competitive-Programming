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
    int deg = 0;
    vector<pair<Node *, int>> neighbours;

    Node(int ID) : id(ID) {};
};

void dfs(Node *node, vector<int> &path, vector<bool> &visEdges) {
    while (node->deg) {
        auto edgeId = node->neighbours[node->deg - 1].second;
        if (visEdges[edgeId]) {
            node->deg--;
            continue;
        }
        visEdges[node->id] = 1;
        auto neighbour = node->neighbours[--node->deg].first;
        dfs(neighbour, path, visEdges);
    }
    path.push_back(node->id);
}

vector<int> Euler(vector<Node *> &nodes, int edges) {
    int odd = 0;
    for (auto &s: nodes) {
        if (s->deg & 1)odd++;
    }

    if (!(!odd or odd == 2))return {};


    vector<int> path;
    vector<bool> visEdges(edges);
    for (auto &node: nodes) {
        if ((!odd and node->deg > 0) or (odd == 2 and node->deg & 1)) {
            dfs(node, path, visEdges);
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
        while (cin >> n >> m) {
            vector<Node *> nodes(n);
            for (int i = 0; i < n; ++i) {
                nodes[i] = new Node(i + 1);
            }
            for (int i = 0; i < m; ++i) {
                int u, v;
                cin >> u >> v;
                nodes[u]->deg++;
                nodes[v]->deg++;
                nodes[u]->neighbours.push_back({nodes[v], i + 1});
                nodes[v]->neighbours.push_back({nodes[u], i + 1});
            }
            auto path = Euler(nodes, m);
            if (path.size() == m + 1) {
                cout << "Possible\n";
            } else cout << "Not Possible\n";
        }
    }
//remember data type long long or int

}
