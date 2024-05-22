#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
vector<int> adj[MAXN];
vector<int> parent(MAXN,-1);
vector<bool> visited(MAXN,false);
int cycle_start=-1,cycle_end=-1;

bool dfs(int v,int par){
    visited[v]=true;
    for(int u:adj[v]){
        if(u==par)continue;
        if(visited[u]){
            cycle_start=u;
            cycle_end=v;
            return true;

        }
        parent[u]=v;
        if(dfs(u,v))return true;
    }
    return false;

}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        
        if(!visited[i]&&dfs(i,parent[i])){
            vector<int> cycle;
            cycle.push_back(cycle_start);
            for(int v=cycle_end;v!=cycle_start;v=parent[v]){
                cycle.push_back(v);
            }
            cycle.push_back(cycle_start);
            if(cycle.size()>=4){
                reverse(cycle.begin(),cycle.end());
                cout<<cycle.size()<<endl;
                for(int u:cycle)cout<<u<<" ";
                cout<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
    


}
