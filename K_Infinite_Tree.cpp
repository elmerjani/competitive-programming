#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll k;cin>>k;
    int n;cin>>n;
    while(n--){
        ll a,b;cin>>a>>b;
        a--;b--;
        ll mx=max(a,b),mn=min(a,b);
        map<ll,ll> mp;
        ll t=0;
        while(mn>0){
            mp[mn]=t;
            mn=(mn-1)/k;
            t++;
        }
        mp[0]=t;
        bool found=false;
        ll ans=0;
        while(mx>0){
            if(mp.find(mx)!=mp.end()){
                found=true;
                cout<<(ans+mp[mx]+1)<<"\n";
                break;
            }
            mx=(mx-1)/k;
            ans++;
        }
        if(!found){
            cout<<ans+mp[0]+1<<"\n";
        }

    }
}