#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;cin>>n;
    vector<ll> a(n);
    ll sumd=0;
    for(int i=0;i<n;i++){
        ll ai,di;
        cin>>ai>>di;
        a[i]=ai;
        sumd+=di;
    }
    sort(a.begin(),a.end());
    ll suma=0;
    for(ll i=0;i<n;i++){
        suma+=((n-i)*a[i]);
    }
    cout<<sumd-suma<<endl;
    return 0;
}