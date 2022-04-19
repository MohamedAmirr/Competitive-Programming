#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    regex p("WUB");
    cout<<regex_replace(s,p," ");//el function deh btshel ay sequence mn el string w t7ot mkano elly ben el double cotation
}