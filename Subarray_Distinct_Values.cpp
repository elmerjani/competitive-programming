#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int  main(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    map<ll,ll> mp;
    ll j=0;
    ll ans=0;
    for(ll i=0;i<n;i++){
        mp[a[i]]++;
        while(mp.size()>k){
            ans+=(n-i);
            mp[a[j]]--;
            if(mp[a[j]]==0)mp.erase(a[j]);
            j++;
        }
    }
    //cout<<ans<<"\n";
    cout<<(n*(n+1))/2-ans<<endl;
    return 0;
    
    
}