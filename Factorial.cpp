#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Z(ll n){
    ll ans=0;
    for(ll i=5;i<=n;i*=5)
        ans+=n/i;
    return ans;
}
int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        cout<<Z(n)<<"\n";
    }
}