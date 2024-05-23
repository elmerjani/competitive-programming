#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(ll a,ll b,ll left,ll right,ll &ans){
    if((a<left || a>right||b<left || b>right))return;
    ans--;
    ll tmp=(right+left)/2;
    solve(a,b,left,tmp,ans);
    solve(a,b,tmp+1,right,ans);

}
int main(){
    ll n,q;
    cin>>n>>q;
    
    while(q--){
        ll a,b;cin>>a>>b;
        ll ans=log2(n)+1;
        solve(a,b,1,n,ans);
        cout<<ans<<"\n";

        
        
        
    }
}