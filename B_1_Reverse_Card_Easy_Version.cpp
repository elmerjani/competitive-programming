#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        long long ans=0;
        for(int d=1;d<=m;d++){
            ans+=(n/d+1)/d;
        }
        cout<<ans-1<<"\n";
    }
}