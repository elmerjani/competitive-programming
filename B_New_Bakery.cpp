#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll somme(ll a,ll b,ll n,ll k){
    return (b+1)*k-(k*(k+1))/2+(n-k)*a;
}
int main(){
    int t;cin>>t;
    while(t--){
        ll a,b,n;
        cin>>n>>a>>b;
        ll ans=0;
        if(b+1-a>=0 &&b+1-a<=min(n,b))ans=max(ans,somme(a,b,n,b+1-a));
        if(b-a>=0 &&b-a<=min(n,b))ans=max(ans,somme(a,b,n,b-a));
        ans=max(ans,somme(a,b,n,0));
        ans=max(ans,somme(a,b,n,min(n,b)));
        cout<<ans<<"\n";
    }

}