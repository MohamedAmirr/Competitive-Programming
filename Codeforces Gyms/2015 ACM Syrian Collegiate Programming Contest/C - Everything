//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

#define all(a)  a.begin(),a.end()
#define endl '\n'

#define int long long


class Trie {
private:
    struct Node {
        bool isLeaf = 1;
        bool flag = 0;
        vector<Node *> children = {};
        int mx, mn;

        Node() : children(vector<Node *>(26, NULL)) {}
    };

    Node *root = NULL;
public:
    Trie() {
        root = new Node;
    }


    void add(string &s, int id) {
        Node *node = root;
        for (auto &ch: s) {
            if (node->children[(ch - 'a')] == NULL) {
                node->isLeaf = 0;
                node->children[(ch - 'a')] = new Node;
            }
            if (node->children[(ch - 'a')]->flag == 0) {
                node->children[(ch - 'a')]->mx = id;
                node->children[(ch - 'a')]->mn = id;
                node->children[(ch - 'a')]->flag = 1;
            } else {
                if (node->children[(ch - 'a')]->mx < id) {
                    node->children[(ch - 'a')]->mx = id;
                }
                if (node->children[(ch - 'a')]->mn > id) {
                    node->children[(ch - 'a')]->mn = id;
                }
            }
            node = node->children[(ch - 'a')];
        }
    }


    int hobaTnia(string &s, int id, int n) {
        int ans = min({id + 1, n - id + 1, (int) s.size() + 1});
        Node *node = root;
        for (int i = 0; i < s.size() - 1; ++i) {
            char ch = s[i];
            int ola = (id - node->children[(ch - 'a')]->mn) + 1;
            int tnia = node->children[(ch - 'a')]->mx - id + 2;
            ans = min(ans, i + 1 + min(ola, tnia));
            node = node->children[(ch - 'a')];
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
    cin >> T;
//remember data type long long or int
    while (T--) {
        int n;
        cin >> n;
        vector<string> v(n);
        Trie hoba;
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            mp[v[i]] = i;
        }
        sort(all(v));
        for (int i = 0; i < n; ++i) {
            hoba.add(v[i], i);
        }
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[mp[v[i]]] = hoba.hobaTnia(v[i], i, n);
        }
        for (int i = 0; i < n; ++i) {
            cout << vec[i] << ' ';
        }
        hoba.del();
        cout << endl;
    }
//remember data type long long or int

}
