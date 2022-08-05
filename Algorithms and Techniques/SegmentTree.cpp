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
    int val = LOO;
    pair<int, int> range = {};

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
        if (hobaOla->val < hobaTnia->val) {
            return hobaOla;
        } else if (hobaTnia->val < hobaOla->val) {
            return hobaTnia;
        }
        Node *hoba = new Node(0, hobaOla->val);
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
        }
    }

    void update(int v, int tl, int tr, int pos, int newVal) {
        if (tr == tl) {
            tree[v]->val = newVal;
        } else {
            int mid = (tl + tr) / 2;
            if (pos <= mid) {
                update(2 * v + 1, tl, mid, pos, newVal);
            } else {
                update(2 * v + 2, mid + 1, tr, pos, newVal);
            }
            Node *node = combine(tree[2 * v + 1], tree[2 * v + 2]);
            tree[v]->val = node->val;
        }
    }

    Node *get(int v, int tl, int tr, int l, int r) {
        if (l > r)return new Node(0, LOO);
        if (tl == l and r == tr) {
            return tree[v];
        } else {
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
    //cin >> T;
//remember data type long long or int
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        SegmentTree hoba;
        hoba.init(v);
        hoba.Build(0, 0, n);
        while (m--) {
            int type;
            cin >> type;
            if (type == 1) {
                int pos, val;
                cin >> pos >> val;
                hoba.update(0, 0, n, pos, val);
            } else {
                int l, r;
                cin >> l >> r;
                cout << hoba.get(0, 0, n, l, r - 1)->val << endl;
            }
        }
    }
//remember data type long long or int

}
