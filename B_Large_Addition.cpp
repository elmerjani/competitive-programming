#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n=s.size()-1;
        if(s[n]-'0'==9){
            cout<<"NO\n";
            continue;
        }
        if(s[0]-'0'!=1){
            cout<<"NO\n";
            continue;
        }
        bool can=true;
        
        n--;
        while(n>=0){
            if(s[n]-'0'==0){
                can=false;
                break;
            }
            n--;
        }
        if(can){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}