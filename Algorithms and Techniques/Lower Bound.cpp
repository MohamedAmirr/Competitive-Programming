#include <bits/stdc++.h>
#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
#define M_PI 3.14159265358979323846
#define endl '\n'
int n,k;
vector<ll >v;

int LowerBound(int x){
    int s=0,e=n-1;
    while(s<e){
        int mid=(s+e)/2;
        if (v[mid]<=x){
            s=mid+1;
        }
        else {
            e=mid;
        }

    }
    if (v[s]>x){
        return s;
    }
    else if (v[s]==x or s==n-1){
        return s+1;
    }
    else return 0;
}


int main() {
    besmellah
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("closing.out", "w", stdout);
#endif
    cin>>n>>k;
    v.resize(n);
    for (int i = 0; i < n; ++i) {cin>>v[i];}
    for (int i = 0; i < k; ++i) {
        int s;
        cin>>s;
        if (LowerBound(s))
            cout << LowerBound(s) << endl;
        else cout<<0<<endl;
    }
}