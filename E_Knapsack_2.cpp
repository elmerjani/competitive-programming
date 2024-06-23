#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5;
const ll INF=1e18;
int main(){
    ll n,W;cin>>n>>W;
    ll w[n],v[n];
    for(int i=0;i<n;i++){
        cin>>w[i]>>v[i];
    }
    vector<bool> dp(MAXN+1,false);
    vector<ll> minweight(MAXN+1,INF);
    dp[0]=true;
    minweight[0]=0;
    vector<vector<bool>> used(MAXN+1,vector<bool>(n,false));
    for(int x=1;x<=MAXN;x++){
        for(int i=0;i<n;i++){
            if(x>=v[i]){
                if(!used[x-v[i]][i] &&minweight[x-v[i]]+w[i]<=W){
                    dp[x]=true;
                    if(minweight[x-v[i]]+w[i]<minweight[x]){
                        minweight[x]=minweight[x-v[i]]+w[i];
                        vector<bool> u=used[x-v[i]];
                        u[i]=true;
                        used[x]=u;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=MAXN;i++){
        //if(i<=200)cout<<dp[i]<<"\n";
        if(dp[i]){
            ans=i;
        }
    }
    cout<<ans<<endl;
    
    
    
    
}