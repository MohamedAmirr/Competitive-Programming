#include <bits/stdc++.h>
#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
#define M_PI 3.14159265358979323846
#define endl '\n'
ll n;
ll power(ll x,ll y){
    if (y==0){return 1;}
    ll sq=power(x,y/2);
    sq=((sq%n)*(sq%n))%n;
    if (y&1)sq*=x;
    return sq%n;
}
int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("closing.out", "w", stdout);
#endif

}