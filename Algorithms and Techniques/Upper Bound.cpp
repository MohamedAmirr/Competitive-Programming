#include <bits/stdc++.h>
#define besmellah ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,k;
vector<ll >v;

int UpperBound(int x){
    int s=0,e=n-1;
    while(s<e){
        int mid=(s+e)/2;
        if (v[mid]>=x){
            e=mid;
        }
        else {
            s=mid+1;
        }

    }
    if (v[s]>=x){
        return s;
    }
    else if (s==n-1)return n;
    else return -1;
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
        cout << UpperBound(s) + 1 << endl;
    }
}