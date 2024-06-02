#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        if(n<m){
            cout<<"No\n";
            continue;
        }
        if((n+m)%2)cout<<"No\n";
        else cout<<"Yes\n";

    }
}
//k-(n-k)=m=>2k-n=m=>2k=m+n;