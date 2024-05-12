#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n=s.length();
        int ans=1;
        bool can=true;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                if(can && s[i-1]=='0'&&s[i]=='1'){
                    can=false;
                    continue;
                }
                else ans++;
            }
        }
        cout<<ans<<"\n";
    }
}