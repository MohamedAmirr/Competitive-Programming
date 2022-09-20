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
const double EPS = 1e-6;
#define M_PI 3.14159265358979323846
#define all(a)  a.begin(),a.end()
#define endl '\n'

int lg(int n) { return 31 - __builtin_clz(n); }

const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};
//#define int long long

struct Node {
    int id = -1;
    bool vis = 0;
    int dis = OO;
    char type = NULL;

    vector<Node *> neighbours;

    Node(int id) : id(id) {};
};

vector<int> ans(105);


int dfs(Node *node, Node *par) {
    int tmp = OO;
    for (auto &s: node->neighbours) {
        if (s == par)continue;
        tmp = min(tmp, dfs(s, node));
    }
    if (tmp == OO)return 0;// so u reach a last level of tree and need to mark as not have a military
    if (tmp == 0) {// once u see this mark u should put military in parent node
        ans[node->id] = 1;
        return 1;
    }
    if (tmp == 1)return INF;// if this node already have a protection u don't need to do anything
    if (node->id == 0)ans[node->id] = 1;// if all nodes have protection but root not have u should mark it
    return 0;
}


signed main() {
    besmellah
//Sky is the limit ❤
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
    //cin >> T;
//remember data type long long or int
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        vector<Node *> nodes;
        nodes.resize(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            nodes[a]->neighbours.push_back(nodes[b]);
            nodes[b]->neighbours.push_back(nodes[a]);
        }
        dfs(nodes[0], nullptr);
        for (int i = 0; i < n; i++)cout << ans[i] << ' ';
        cout << endl;
    }
//remember data type long long or int

}
