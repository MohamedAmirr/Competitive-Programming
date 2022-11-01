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
    int id = -1;
    int vis = 0;
    Node *par = nullptr;

    vector<Node *> neighbours;

    Node(int id) : id(id) {};
};

bool ans = 1;

void dfs(Node *node, Node *par = nullptr) {
    node->vis = 2;
    for (auto &s: node->neighbours) {
        if (node != par) {
            if (s->vis == 2) {
                ans = 0;
//                return;
            }
            if (!s->vis)
                dfs(s, node);
        }
    }
    node->vis = 1;
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
        int n;
        cin >> n;
        map<string, int> mp;
        vector<Node *> nodes;
        vector<pair<string, string>> v(n);
        for (int i = 0, j = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second;
            if (mp.find(v[i].first) == mp.end())
                mp[v[i].first] = j++;
            if (mp.find(v[i].second) == mp.end())
                mp[v[i].second] = j++;

        }
        nodes.resize(mp.size());
        for (int i = 0; i < mp.size(); ++i) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < n; ++i) {
            nodes[mp[v[i].first]]->neighbours.push_back(nodes[mp[v[i].second]]);
            nodes[mp[v[i].second]]->par = nodes[mp[v[i].first]];
        }
        bool ch = 0;
        for (int i = 0; i < mp.size(); ++i) {
            if (nodes[i]->par == nullptr) {
                ch = 1;
                dfs(nodes[i]);
            }
        }
        if (!ans or !ch) {
            cout << "No more comedians++" << endl;
        } else {
            cout << "I disagree with the advisor\n";
        }
    }
//remember data type long long or int

}
