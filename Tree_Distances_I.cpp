#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1;
vector<int> adj[MAXN];
vector<int> parent(MAXN,-1);
int dfs(int start,int par){
    int ans=0;
    for(int x:adj[start]){
        if(x==par)continue;
        parent[x]=start;
        ans=max(ans,1+dfs(x,start));
    }
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


}