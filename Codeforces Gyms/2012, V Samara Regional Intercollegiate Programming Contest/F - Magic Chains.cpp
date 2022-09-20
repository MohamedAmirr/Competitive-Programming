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
const ll N = 6e5 + 5;
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

ll pw[11];
vector<ll> adj[N + 5];
vector<ll> dis(N + 5, LOO);

void Hashing() {
    pw[0] = 1;
    for (int i = 1; i < 11; ++i) {
        pw[i] = pw[i - 1] * 26;
    }
}

map<int, int> par;

void dijkstra() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({0, 1});
    dis[0] = 1;
    while (pq.size()) {
        auto node = pq.top();
        pq.pop();
        for (auto &s: adj[node.first]) {
            if (dis[s] > 1 + node.second) {
                dis[s] = 1 + node.second;
                pq.push({s, dis[s]});
                par[s] = node.first;
            }
        }
    }
}

signed main() {
    besmellah
//Sky is the limit ❤
//#ifdef CLION
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//#else
    //freopen("", "r", stdin);
//#endif
    int T = 1;
    Hashing();
    //cin >> T;
//remember data type long long or int
    while (T--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        map<pair<int, ll>, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
                ll code = 0;
                for (int k = 0; k < v[i].size(); ++k) {
                    if (k == j)continue;
                    code += pw[k] * (v[i][k] - 'a');
                }
                mp[{code, j}].push_back(i);
            }
        }
        for (auto &s: mp) {
            for (int i = 0; i < s.second.size(); ++i) {
                for (int j = 0; j < s.second.size(); ++j) {
                    if (i == j)continue;
                    adj[s.second[j]].push_back(s.second[i]);
                    adj[s.second[i]].push_back(s.second[j]);
                }
            }
        }
        dijkstra();
        int end = n - 1;
        if (dis[n - 1] == LOO) {
            cout << "FAIL\n";
            continue;
        }
        stack<int> st;
        while (end != 0) {
            st.push(end);
            end = par[end];
        }
        st.push(end);
        cout << st.size() << endl;
        while (st.size()) {
            cout << v[st.top()] << endl;
            st.pop();
        }

    }
//remember data type long long or int

}
