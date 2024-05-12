#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int   MAXN=1e5+1;
vector<int> adj[MAXN];
vector<vector<int>> components;
vector<bool> visited(MAXN,false);
void dfs(int u,vector<int> &component){
    component.push_back(u);
    visited[u]=true;
    for(int u:adj[u]){
        if(!visited[u]){
        dfs(u,component);
        }
    }
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,component);
            components.push_back(component);
        }
        
    }
    cout<<components.size()-1<<endl;
    for(int i=0;i<components.size()-1;i++){
        
        cout<<components[i][0]<<" "<<components[i+1][0]<<"\n";
    }


}