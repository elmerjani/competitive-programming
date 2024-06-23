#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,W;cin>>n>>W;
    ll w[n],v[n];
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<bool>> used(W+1,vector<bool>(n,false));
    vector<ll> dp(W+1,0);
    for(ll x=1;x<=W;x++){
        for(int i=0;i<n;i++){
            if(x>=w[i]){
                if(!used[x-w[i]][i] &&dp[x-w[i]]+v[i]>dp[x]){
                    vector<bool> vv=used[x-w[i]];
                    vv[i]=true;
                    used[x]=vv;
                    dp[x]=dp[x-w[i]]+v[i];
                    }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=W;i++)ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;

    
}