#include <bits/stdc++.h>
#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
#define M_PI 3.14159265358979323846
#define endl '\n'
unsigned CountBits(int n){
    return (int)log2(n)+1;
}
int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("closing.out", "w", stdout);
#endif
    cout<<CountBits(31);
}