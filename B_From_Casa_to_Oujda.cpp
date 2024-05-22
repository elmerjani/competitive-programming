#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s;cin>>s;
    int count1=0,count2=0;
    bool wejda=s[0]=='S'?true:false;
    for(int i=0;i<n;i++){
        if(s[i]=='S'){
            if(!wejda)count2++;
            wejda=true;
        }
        else  {
            if(wejda)count1++;
            wejda=false;
            
        }
    }
    if(count1>count2)cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    return 0;
    
}