#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
const ll MAXN =1e6;
vector<ll> facts;
vector<ll> factInv;

ll fact(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

ll pow(ll a, ll b, ll mod) {
    if(a==1)return 1;
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    facts.push_back(1);
    factInv.push_back(1);
    for(int i=1;i<=MAXN;i++){
        facts.push_back((facts[i-1]*i)%MOD);
        factInv.push_back((factInv[i-1]*pow(i,MOD-2,MOD))%MOD);
    }
    
    int t;cin>>t;
    while(t--){
        ll a,b; cin >> a >> b;
        cout<<(((facts[a]*factInv[b])%MOD)*factInv[a-b])%MOD<<"\n";
    }
}