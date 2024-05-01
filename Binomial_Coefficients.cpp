#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;

ll fact(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

ll pow(ll a, ll b, ll mod) {
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
    
    int t;cin>>t;
    while(t--){
    ll n, m; cin >> n >> m;

    ll top = fact(n ), bottom = fact(m) * fact(n-m);

    cout << (top * pow(bottom, MOD - 2, MOD)) % MOD << endl;
    }
}