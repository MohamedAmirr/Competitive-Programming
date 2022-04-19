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
#define all(a)  a.begin(),a.end()
#define M_PI 3.14159265358979323846
#define endl '\n'
const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};
#define int long long

struct Node {
    int id = -1;
    bool vis = 0;
    char type = NULL;

    vector<Node *> neighbours;

    Node(int id, char type) : id(id), type(type) {};
};


void dfs(Node *node) {
    node->vis = 1;
    for (auto &s: node->neighbours) {
        if (!s->vis) {
            dfs(s);
        }
    }
}


signed main() {
    besmellah
// لا تحسبن المجد تمرا انت اكله لن تبلغ المجد حتي تلعق الصبر ❤
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
#endif
    int T = 1;
//    cin >> T;
//remember data type long long or int
    while (T--) {

    }
//remember data type long long or int

}