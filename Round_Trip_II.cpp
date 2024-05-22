#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
vector<int> adj[MAXN];
vector<char> color(MAXN,0);
vector<int> parent(MAXN,-1);
int cycle_start=-1,cycle_end=-1;

bool dfs(int v){
    color[v]=1;
    for(int u:adj[v]){
        if(color[u]==0){
            parent[u]=v;
            if(dfs(u))return true;
        }
        else if(color[u]==1){
            cycle_start=u;
            cycle_end=v;
            return true;

        }
    }
    color[v]=2;
    return false;


}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!color[i] &&dfs(i)){
            vector<int> cycle;
            cycle.push_back(cycle_start);
            for(int v=cycle_end;v!=cycle_start;v=parent[v]){
                cycle.push_back(v);
            }
            cycle.push_back(cycle_start);
            if(cycle.size()>=3){
                cout<<cycle.size()<<endl;
                reverse(cycle.begin(),cycle.end());
                for(int x:cycle){
                    cout<<x<<" ";
                }
                cout<<endl;
                return 0;
            }

            
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;

}