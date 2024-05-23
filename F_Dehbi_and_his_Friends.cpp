#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

void dijkstra(int start,vector<int> &dist, vector<pair<int,int>> adj[]){
    dist[start]=0;
    set<pair<int,int>> q;
    q.insert({0,start});
    while(!q.empty()){
        int v=(*q.begin()).second;
        q.erase(q.begin());
        for(auto  p:adj[v]){
            int to=p.first;
            int   len=p.second;
            if(dist[v]+len<dist[to]){
                q.erase({dist[to],to});
                dist[to]=dist[v]+len;
                q.insert({dist[to],to});
            }

        }
    }

}
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        //n++;
        vector<pair<int,int>> adj[n+1];
        vector<int> dist(n+1,INF);
        for(int i=0;i<m;i++){
            int u,v,w;cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int x;cin>>x;
        vector<int> dehbis_friends(x);
        for(int i=0;i<x;i++){
            cin>>dehbis_friends[i];
        }
        int start;cin>>start;
        dijkstra(start,dist,adj);
        int ans=INF;
        for(int i:dehbis_friends){
            if(dist[i]<ans)ans=dist[i];
        }
        if(ans==INF)cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }
}