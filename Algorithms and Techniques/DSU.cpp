#include <bits/stdc++.h>

#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e5;
#define M_PI 3.14159265358979323846
#define endl '\n'
const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
const int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
const int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};

int arr[N + 5];

int findRoot(int i) {
    if (arr[i] != i) {
        return arr[i] = findRoot(arr[i]);
    } else {
        return i;
    }
}

void DSU(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a != b){
        //arr[b]+=arr[a] : lw nta btsht8l bl tre2a bta3t code ncode w hwa by3ml initialize kolo b -1
        arr[b] = a;
    }

    else
        return;
}

int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //    freopen("closing.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 5; ++i) {
        arr[i] = i;
    }
    while (m--) {
        string s;
        int u, v;
        cin >> s >> u >> v;
        if (s == "union") DSU(u, v);
        else if (arr[u] != arr[v])
            findRoot(u) == findRoot(v) ? cout << "YES\n" : cout << "NO\n";
        else if (arr[u] == arr[v])
            cout << "YES\n";
    }
}
