#include <bits/stdc++.h>
using namespace std;
void sieve(int n){
    bool arr[n+1];
    memset(arr,true,n+1);
    for (long long i = 2; i*i <= (n); ++i) {
        if (arr[i]){
            for (int j = i*i; j <= (n); j+=i) {
                arr[j]=false;
            }
        }
    }
    for (int i = 2; i < n+1; ++i) {
        if (arr[i]){
            cout<<i<<endl;
        }
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
