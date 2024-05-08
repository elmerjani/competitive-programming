#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
ll fact(ll n){
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
        ans%=MOD;
    }
    return ans;
}
int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        cout<<(((n*(n-1))%MOD)*fact(n))%MOD<<"\n";
    }

}