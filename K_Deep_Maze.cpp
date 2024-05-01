#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
ll fact(ll n){
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans=(ans*i)%MOD;
        
    }
    return ans;
 
}
ll binpow(ll a,ll b,ll mod){
    if(b==0)return 1;
    ll res=binpow(a,b/2,mod);
    if(b%2==0) return (res*res)%mod;
    return (((a*res)%mod)*res)%mod;
}
int main(){
    ll n,m;
    cin>>n>>m;
    ll top=fact(n+m-2),bottom=(fact(n-1)*fact(m-1))%MOD;
    cout<<(top*binpow(bottom,MOD-2,MOD))%MOD<<"\n";
 
    
 
}