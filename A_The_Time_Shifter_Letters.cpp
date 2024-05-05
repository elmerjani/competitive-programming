#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//vector<ll> facts(26);
const ll MOD = 1e9 + 7;
ll binpow(ll a,ll b,ll mod){
    if(b==0)return 1;
    ll tmp=binpow(a,b/2,mod);
    if(b%2==0)return (tmp*tmp)%mod;
    return (((a*tmp)%mod)*tmp)%mod;
}
ll factorial(ll n) {
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans=(ans*i)%MOD;
    }
    return ans;
}

int main() {
    
    //facts[0] = 1;
    //for(ll i=1;i<26;i++){
        //facts[i] = (facts[i-1] * i) % MOD;

    //}
    int n;
    string S1, S2;
    cin >> n >> S1 >> S2;
    ll bottom=1;
    ll steps = 0;
    for (int i = 0; i < n; ++i) {
        ll diff = S2[i] - S1[i];
        if (diff < 0) {
            cout<<-1<<"\n";
            return 0;
        }  
        steps += diff;
        bottom=(bottom*factorial(diff))%MOD;
    }
    ll top = factorial(steps);
    cout<<(top*binpow(bottom,MOD-2,MOD))%MOD<<"\n";

    return 0;
}
