#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
typedef long long ll;
const ll INF=1e14;
vector<pair<int,ll>> adj[MAXN];
vector<bool> used(MAXN,false);
vector<ll> dist(MAXN,INF);
void dijkstra(int start,int n){
    dist[start]=0;
    for(int i=1;i<=n;i++){
        int v=-1;
        for(int j=1;j<=n;j++){
            if(!used[j] &&(v==-1 || dist[j]<dist[v])){
                v=j;
            }
        }
        if(dist[v]==INF)break;
        used[v]=true;
        for(auto  p:adj[v]){
            int to=p.first;
            ll len=p.second;
            if(dist[v]+len<dist[to]){
                dist[to]=dist[v]+len;
            }

        }
    }

}
int main(){
    int n,m;cin>>n>>m;
    for(int    i=0;i<m;i++){
        int u,v;ll w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        //adj[v].push_back({u,w});
    }
    dijkstra(1,n);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
    return 0;


}