#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,x;cin>>n>>x;
    ll sum[n+1];
    sum[0]=0;
    ll s=0;
    for(int i=1;i<=n;i++){
        ll ai;cin>>ai;
        s+=ai;
        sum[i]=s;
    }
    map<ll,ll> mp;
    ll count=0;
    for(int i=0;i<=n;i++){
        count+=mp[sum[i]-x];
        mp[sum[i]]++;
        
    }
    cout<<(count)<<endl;
    return 0;

}