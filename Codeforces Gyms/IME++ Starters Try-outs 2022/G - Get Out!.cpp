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

class Trie {
private:
    struct Node {
        bool isLeaf = 1;
        vector<Node *> children = {};

        Node() : children(vector<Node *>(10, NULL)) {}
    };

    Node *root = NULL;
public:
    Trie() {
        root = new Node;
    }


    void add(string &s, int id) {
        Node *node = root;
        for (auto &ch: s) {
            if (node->children[(ch - '0')] == NULL) {
                node->isLeaf = 0;
                node->children[(ch - '0')] = new Node;
            }
            node = node->children[(ch - '0')];
        }
    }

    string dfs(deque<deque<int>> &hoba) {
        string ans;
        Node *node = root;
        while (hoba.size()) {
            deque<int> d = hoba.front();
            for (auto &s: d) {
                if (node->children[s] != NULL) {
                    node = node->children[s];
                    hoba.pop_front();
                    ans.push_back(s + '0');
                    break;
                }
            }

        }
        return ans;
    }

    void del(Node *x) {
        for (auto &i: x->children) {
            if (i != nullptr)
                del(i);
        }
        delete x;
    }

    void del() {
        del(root);
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
        int n;
        cin >> n;
        Trie *trie;
        trie = new Trie;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            trie->add(v[i], i);
        }
        int q;
        cin >> q;

        while (q--) {
            string s;
            cin >> s;
            deque<deque<int>> hoba;
            for (int i = 0; i < s.size(); ++i) {
                deque<pair<int, int>> bestDigNeeded;
                for (int j = 9; j >= 0; --j) {
                    bestDigNeeded.push_back({(s[i] - '0' + j) % 10, j});
                }
                sort(all(bestDigNeeded), greater<>());
                deque<int> hobaGowa;
                for (auto &s: bestDigNeeded) {
                    hobaGowa.push_back(s.second);
                }
                hoba.push_back(hobaGowa);
            }
            cout << trie->dfs(hoba) << endl;
        }
    }
//remember data type long long or int

}
