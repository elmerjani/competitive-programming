#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
vector<ll> freq(26,0);
ll fact(ll n){
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
        ans%=MOD;
    }
    return ans;
}
ll binpow(ll a ,ll b ,ll mod){
    if(b==0 )return 1;
    ll res=binpow(a,b/2,mod);
    if(b%2==0) return (res*res)%mod;
    return (((a*res)%mod)*res)%mod;
}
int main(){
    string s;cin>>s;
    ll n=s.size();
    for(int i=0;i<n;i++){
        freq[s[i]-'a']++;
    }
    ll ans=1;
    for(int i=0;i<26;i++){
        ans=(ans*(fact(freq[i])))%MOD;
    }
    cout<<(fact(n)*binpow(ans,MOD-2,MOD))%MOD<<"\n";
}