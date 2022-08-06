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
#define int long long


struct Node {
    int id = 0;
    int val = 0;
    pair<int, int> range = {};
    int lazy = 0;//value that from it u know that there is no lazy Ex: find sum so lazy = 0
    Node(int id, int val) : id(id), val(val) {};

//    Node(int val) : val(val) {};

};


struct SegmentTree {
    vector<Node *> tree;
    vector<int> arr;

    void init(vector<int> &v) {
        int n = 4 * v.size();
        arr = v;
        tree.resize(n);
        for (int i = 0; i < n; ++i) {
            tree[i] = new Node(i + 1, 0);
        }
    }

    Node *combine(Node *hobaOla, Node *hobaTnia) {
        Node *hoba = new Node(0, hobaOla->val + hobaTnia->val);
        return hoba;
    }

    void Build(int v, int tl, int tr) {
        if (tr == tl) {
            tree[v]->val = arr[tl];
        } else {
            int mid = (tl + tr) / 2;
            Build(2 * v + 1, tl, mid);
            Build(2 * v + 2, mid + 1, tr);
            Node *node = combine(tree[2 * v + 1], tree[2 * v + 2]);
            tree[v]->val = node->val;
            tree[v]->range = {tl, tr};
            tree[v * 2 + 1]->range = {tl, mid};
            tree[v * 2 + 2]->range = {mid + 1, tr};
        }
    }

    void confirmLazy(int v) {
        tree[2 * v + 1]->val += (tree[v]->lazy * (tree[2 * v + 1]->range.second - tree[2 * v + 1]->range.first + 1));
        tree[2 * v + 2]->val += (tree[v]->lazy * (tree[2 * v + 2]->range.second - tree[2 * v + 2]->range.first + 1));
        tree[2 * v + 1]->lazy += tree[v]->lazy;
        tree[2 * v + 2]->lazy += tree[v]->lazy;
        tree[v]->lazy = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int newVal) {
        if (l > r)return;
        if (tl == l and tr == r) {
            tree[v]->lazy += newVal;
            tree[v]->val += (newVal * ((tr - tl + 1)));
        } else {
            confirmLazy(v);
            int mid = (tl + tr) / 2;
            if (mid >= l)
                update(2 * v + 1, tl, mid, l, min(r, mid), newVal);
            if (mid + 1 <= r)
                update(2 * v + 2, mid + 1, tr, max(l, mid + 1), r, newVal);
            Node *node = combine(tree[2 * v + 1], tree[2 * v + 2]);
            tree[v]->val = node->val;
        }
    }

    Node *get(int v, int tl, int tr, int l, int r) {
        if (l > r)return new Node(0, 0);
        if (tl == l and r == tr) {
            return tree[v];
        } else {
            confirmLazy(v);
            int mid = (tl + tr) / 2;
            Node *hobaOla = get(2 * v + 1, tl, mid, l, min(r, mid));
            Node *hobaTnia = get(2 * v + 2, mid + 1, tr, max(l, mid + 1), r);
            return combine(hobaOla, hobaTnia);
        }
    }
};


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
    cin >> T;
//remember data type long long or int
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n, 0);
        SegmentTree hoba;
        hoba.init(v);
        hoba.Build(0, 0, n - 1);
        while (m--) {
            int type;
            cin >> type;
            if (type == 1) {
                int l, r;
                cin >> l >> r;
                cout << hoba.get(0, 0, n - 1, l - 1, r - 1)->val << endl;
            } else {
                int p, q, val;
                cin >> p >> q >> val;
                hoba.update(0, 0, n - 1, p - 1, q - 1, val);
            }
        }
    }
//remember data type long long or int

}
