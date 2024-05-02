#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;cin>>n>>q;
    int xorArr[n+1]={};
    int x=0;
    for(int i=1;i<=n;i++){
        int ai;cin>>ai;
        x^=ai;xorArr[i]=x;
    }
    while(q--){
        int a,b;cin>>a>>b;
        cout<<(xorArr[b]^xorArr[a-1])<<"\n";
    }
}