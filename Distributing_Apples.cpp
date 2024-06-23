#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll binpow(ll a ,ll b,ll mod){
    if(b==0)return 1;
    ll tmp=binpow(a,b/2,mod);
    if(b%2==0)return (tmp*tmp)%mod;
    return (((a*tmp)%mod)*tmp)%mod;
}
ll fact(ll a,ll mod){
    ll ans=1;
    for(ll i=1;i<=a;i++){
        ans*=i;
        ans%=mod;
    }
    return ans;
}
ll C(ll k,ll n,ll mod){
    if(k>n)return 0;
    return (fact(n,mod)*binpow((fact(k,mod)*fact(n-k,mod))%mod,mod-2,mod))%mod;
}
int main(){
    ll n,m;
    cin>>n>>m;
    cout<<C(n-1,n+m-1,MOD)<<"\n";

    
    


}