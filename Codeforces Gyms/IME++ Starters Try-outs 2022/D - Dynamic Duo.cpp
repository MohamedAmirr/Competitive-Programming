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
    ll val = 0;
    pair<int, int> range = {};
    ll lazy = 0;//value that from it u know that there is no lazy Ex: find sum so lazy = 0
    Node(int id, ll val) : id(id), val(val) {};

//    Node(int val) : val(val) {};

};

Node *dummy;
Node *tmp;


struct SegmentTree {
    vector<Node *> tree;
    vector<ll> arr;

    void init(vector<ll> &v) {
        int n = 4 * v.size();
        arr = v;
        tree.resize(n);
        for (int i = 0; i < n; ++i) {
            tree[i] = new Node(i + 1, 0);
        }
    }

    Node *combine(Node *hobaOla, Node *hobaTnia) {
        if (hobaOla->val < hobaTnia->val) {
            tmp->val = hobaOla->val;
            return tmp;
        } else if (hobaTnia->val < hobaOla->val) {
            tmp->val = hobaTnia->val;
            return tmp;
        }
        tmp->val = hobaTnia->val;
        return tmp;
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
        tree[2 * v + 1]->val += (tree[v]->lazy);
        tree[2 * v + 2]->val += (tree[v]->lazy);
        tree[2 * v + 1]->lazy += tree[v]->lazy;
        tree[2 * v + 2]->lazy += tree[v]->lazy;
        tree[v]->lazy = 0;
    }

    void update(int v, int tl, int tr, int l, int r, ll newVal) {
        if (l > r)return;
        if (tl == l and tr == r) {
            tree[v]->lazy += newVal;
            tree[v]->val += (newVal);
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

    ll get(int v, int tl, int tr, int pos) {
//        if (l > r)return LOO;
        if (tl == pos and pos == tr) {
            return tree[v]->val;
        } else {
            confirmLazy(v);
            int mid = (tl + tr) / 2;
            if (pos <= mid)
                return get(2 * v + 1, tl, mid, pos);
            else
                return get(2 * v + 2, mid + 1, tr, pos);
        }
    }

    void del() {
        for (auto &i: tree) {
            if (i != nullptr)
                delete i;
        }
        tree.clear();
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
        int n, q;
        cin >> n >> q;
        SegmentTree hoba;
        vector<ll> v(n);
        tmp = new Node(0, 0);
        hoba.init(v);
        while (q--) {
            char t;
            cin >> t;
            if (t == '!') {
                int a, b, c;
                cin >> a >> b >> c;
                a--, b--;
                hoba.update(0, 0, n, a, b, c);
            } else {
                int a, b;
                cin >> a >> b;
                if (hoba.get(0, 0, n, a - 1) >= b) {
                    cout << "yes sir\n";
                    hoba.update(0, 0, n, a - 1, a - 1, -b);
                } else {
                    cout << "negative\n";
                }
            }
        }
    }
//remember data type long long or int

}
