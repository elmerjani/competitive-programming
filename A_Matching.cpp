#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        if(s[0]=='0'){
            cout<<0<<"\n";
            continue;
        }
        int ans=1;
        if(s[0]=='?')ans=9;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]=='?')ans*=10;

        }
        cout<<ans<<"\n";
    }
}