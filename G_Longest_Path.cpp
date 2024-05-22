#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
vector<int> adj[MAXN];
vector<int> dp(MAXN,-1);
int mx=0;
int dfs(int u){
    if(dp[u]!=-1)return dp[u];
    int ma=0;
    for(int v:adj[u]){
        
        ma=max(ma,1+dfs(v));
        
    }
    dp[u]=ma;
    if(ma>mx)mx=ma;
    return ma;

}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    //int ans=0;
    for(int i=1;i<=n;i++){
        if(dp[i]==-1){
            dfs(i);
        }
    }
    //for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    //cout<<"\n";
    cout<<mx<<endl;
    return 0;

}