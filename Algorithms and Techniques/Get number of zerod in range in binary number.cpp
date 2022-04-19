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
const ll N = 2e6;
#define all(a)  a.begin(),a.end()
#define M_PI 3.14159265358979323846
#define endl '\n'
const int dx[] = {+0, +0, +1, -1, +1, -1, +1, -1};
const int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
int knightDx[] = {+1, -1, +2, +2, -2, -2, +1, -1};
int knightDy[] = {+2, +2, +1, -1, +1, -1, -2, -2};

//function that get #zeros in range in binary

ll F(ll x,ll j){
    return (x>>(j+1)<<j)+min(x%(1<<(j+1)),1LL*1<<j);
}

int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T=1;
    cin>>T;
    while(T--){
        ll l,r;
        cin>>l>>r;
        ll z=r;
        for (int i = 0; i < 18; ++i) {
            z=min(z,F(r+1,i)-F(l,i));
        }
        cout<<z<<endl;
    }
}