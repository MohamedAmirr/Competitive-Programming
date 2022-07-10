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
const ll N = 2e5;
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
    int id = -1;
    int vis = 0;
    int dis = LOO;
    char type = NULL;
    vector<pair<Node *, pair<int, int>>> neighbours;

    void hoba() {
        dis = LOO;
    }

    Node(int id) : id(id) {};
};

vector<int> dp(N + 5, LOO);
int n, t;

vector<Node *> nodes;

bool dijkstra(int mid, vector<int> &v) {
    Node *src = nodes[0];
    priority_queue<pair<int, Node *>> pq;
    pq.push({0, src});
    for (int i = 1; i < n; ++i) {
        nodes[i]->hoba();
    }
    src->dis = 0;
    while (pq.size()) {
        Node *node = pq.top().second;
        int currCost = pq.top().first;
        pq.pop();
        if (currCost > t) {
            if (node->id == n)node->dis = LOO;
            continue;
        }
        if (node->id == n)continue;
        for (auto &to: node->neighbours) {
            if (to.first->dis > node->dis + to.second.first and to.second.second <= mid) {
                to.first->dis = node->dis + to.second.first;
                pq.push({to.first->dis, to.first});
            }
        }
    }
    return nodes[n - 1]->dis != LOO;
}

pair<int, int> BS(vector<int> &v) {
    ll l = 0, r = v.size(), mid;
    pair<int, int> ans = {LOO, LOO};
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (dijkstra(v[mid], v)) {
            r = mid - 1;
            if (ans.first > v[mid])
                ans.first = min(v[mid], ans.first), ans.second = nodes[n - 1]->dis;
        } else l = mid + 1;
    }
    return ans;
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
        int m;
        cin >> n >> m;
        nodes.resize(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node(i + 1);
        }
        vector<int> v;
        for (int i = 0; i < m; ++i) {
            int a, b, tt, s;
            cin >> a >> b >> tt >> s;
            a--, b--;
            v.push_back(s);
            nodes[a]->neighbours.push_back({nodes[b], {tt, s}});
            nodes[b]->neighbours.push_back({nodes[a], {tt, s}});
        }
        sort(all(v));
        cin >> t;
        pair<int, int> ans = BS(v);
        if (ans.first >= LOO) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << ans.first << ' ';
            cout << ans.second << '\n';
        }
    }
//remember data type long long or int

}
