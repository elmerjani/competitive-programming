#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n=s.length();
        bool can=false;
        for(int i=0;i<n;i++){
            if(s[i]!=s[0]){
                
                
                char c=s[0];
                s[0]=s[i];
                s[i]=c;
                
            
                can=true;
                break;
            }
            
        }
        if(can){
            cout<<"YES"<<"\n";
            cout<<s<<"\n";
            
        }
        else cout<<"NO"<<"\n";
    }
}
