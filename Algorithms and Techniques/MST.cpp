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
const ll N = 1e5;
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
    int id;
    Node *par = this;
    int sz = 1;

    Node(int id) : id(id) {};
};

struct Edge {
    Node *from, *to;
    int wght = 0;

    Edge(Node *from, Node *to, int wght) : from(from), to(to), wght(wght) {};
};

Node *findPar(Node *node) {
    if (node == node->par)
        return node;
    return node->par = findPar(node->par);
}

void combine(Node *a, Node *b) {
    a = findPar(a);
    b = findPar(b);
    if (a == b)return;
    if (a->sz < b->sz) {
        swap(a, b);
    }
    b->par = a;
}

ll Kruskal(vector<Edge> &edges) {
    ll sum = 0;
    for (auto &s: edges) {
        if (findPar(s.to) != findPar(s.from)) {
            combine(s.to, s.from);
            sum += s.wght;
        }
    }
    return sum;
}

bool cmp(Edge &e1, Edge &e2) {
    return e1.wght < e2.wght;
}

signed main() {
    besmellah
//Sky is the limit ❤
#ifdef CLION
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
#endif
    int T = 1;
    //cin >> T;
//remember data type long long or int
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<Node *> nodes(n);
        vector<Edge> edges;
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node(i + 1);
        }
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            edges.push_back(Edge(nodes[a], nodes[b], c));
        }
        sort(all(edges), cmp);
        cout << Kruskal(edges);

    }
//remember data type long long or int

}
