#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1;
vector<int> adj[MAXN];
vector<int> color(MAXN,-1);
bool is_bipartite(int n){
    bool is_bipartite=true;
    queue<int> q;
    q.push(1);
    color[1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(color[v]==-1){
                color[v]=1-color[u];
                q.push(v);
            }
            else if(color[v]==color[u]){
                is_bipartite=false;
                break;
            }
        }
        if(!is_bipartite)break;
    }
    return is_bipartite;


}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[i]={u,v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(is_bipartite(n)){
        cout<<"YES"<<"\n";
        for(int i=0;i<m;i++){
            if(color[edges[i].first]==0&& color[edges[i].second]==1)cout<<1;
            else cout<<0;
        }
        cout<<"\n";
        
        

    }
    else {
        cout<<"NO"<<"\n";
    }
}