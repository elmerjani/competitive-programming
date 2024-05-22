#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,q;
    cin>>n>>q;
    while(q--){
        ll a,b;cin>>a>>b;
        if(abs(a-b)==1){
            if(a%2)cout<<1;
            else cout<<2;
        }
        else {
            ll ans=(log2(abs(a-b)));
            cout<<ans+1;

        }
        cout<<"\n";
        
        
    }
}