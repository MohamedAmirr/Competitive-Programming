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
    int vis = 0;
    int init, goal;
    vector<Node *> Children;

    Node(int i) {
        id = i;
    }
};

queue<int> q;
bool ch = false;

void dfs(Node *node) {
    node->vis = 2;
    for (auto &child: node->Children) {
        if (child->vis == 2) {
            ch = true;
            return;
        }
        if (!child->vis) {
            dfs(child);
            if (ch)return;
        }
    }
    node->vis = 1;
    q.push(node->id);
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
        while (cin >> n >> m and (n or m)) {
            vector<Node *> gr(n);
            while (!q.empty())q.pop();
            int ID = 0;
            for (auto &g: gr) {
                g = new Node(++ID);
            }
            for (int i = 0; i < m; ++i) {
                int a, b;
                cin >> a >> b;
                a--, b--;
                gr[b]->Children.push_back(gr[a]);
            }
            for (int i = 0; i < n; ++i) {
                if (!gr[i]->vis) {
                    dfs(gr[i]);
                    if (ch)break;
                }
            }
            if (ch) {
                cout << "IMPOSSIBLE\n";
                while (!q.empty())q.pop();

            }
            ch = false;
            while (q.size()) {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
}