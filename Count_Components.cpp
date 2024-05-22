#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
vector<int> adj[MAXN];
vector<bool> used(MAXN,false);
void dfs(int v){
    used[v]=true;
    for(int x:adj[v]){
        if(!used[x]){
            dfs(x);
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<endl;
    return 0;

}