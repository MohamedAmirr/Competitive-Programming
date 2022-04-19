#include <iostream>
using namespace std;
long long fact(int n){
    long long res=1;
    for (int i = 2; i <= n; ++i) {
        res*=i;
    }
    return res;
}
long long nCr(int n, int r){
    return fact(n)/(fact(r)* fact(n-r));
}
long long nPr(int n,int r){
    return fact(n)/fact(n-r);
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
