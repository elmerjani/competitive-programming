#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
vector<int> adj[MAXN];
vector<int> color(MAXN,0);
bool isBipartite(int start){
    queue<int> q;
    q.push(start);
    color[start]=1;
    while(!q.empty()){
        int v=q.front();q.pop();
        for(int u:adj[v]){
            if(color[u]==0){
                color[u]=color[v]==1?2:1;
                q.push(u);
            }
            else{
                if(color[u]==color[v])return false;
            }
        }
    }
    return true;
}
main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            if(!isBipartite(i)){
                cout<<"IMPOSSIBLE"<<"\n";
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<color[i]<<" ";
    cout<<"\n";
    return 0;


}