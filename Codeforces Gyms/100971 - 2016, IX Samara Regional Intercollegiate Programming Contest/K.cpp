#include <bits/stdc++.h>
 

using namespace std;

#define BEMWA ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int main(){
    BEMWA
    
    int t = 1;
    //cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long n = s.length();
        long long ans1 = n/2;
        long long ans2 = n/2;
        for(int i = 0; i < n/2; ++i){
            if(s[i] != s[n - i - 1]){
                ans1 = i;
                ans2 = n - i - 1;
                break;
            }
        }
        string tmp3 = s.substr(0,ans1) + s.substr(ans1+1);
        string tmp1 = s.substr(0,ans1) + s.substr(ans1+1);
        string tmp2 = s.substr(0,ans2) + s.substr(ans2+1);
        string tmp4 = s.substr(0,ans2) + s.substr(ans2+1);
        reverse(tmp4.begin(), tmp4.end());
        reverse(tmp3.begin(), tmp3.end());
        if(tmp3 == tmp1){
            cout << "YES\n";
            cout << ans1+1 << endl;
        }else if(tmp4 == tmp2){
            cout << "YES\n";
            cout << ans2+1 << endl;
        }else{
            cout << "NO\n";
        }
    }
    
    return 0;       
}
