#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
typedef long long ll;
const ll INF=1e14;
vector<pair<int,ll>> adj[MAXN];
vector<ll> dist(MAXN,INF);
vector<int> parent(MAXN,-1);
void dijkstra(int start,int n){
    dist[start]=0;
    set<pair<ll,int>> q;
    q.insert({0,start});
    while(!q.empty()){
        int v=(*q.begin()).second;
        q.erase(q.begin());
        for(auto p:adj[v]){
            int to=p.first;
            if(to==parent[v])continue;
            ll len=p.second;
            if(dist[v]+len<dist[to]){
                q.erase({dist[to],to});
                dist[to]=dist[v]+len;
                q.insert({dist[to],to});
                parent[to]=v;
            }
        }
    }

}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;ll w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dijkstra(1,n);
    if(dist[n]==INF){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> path;
    for(int v=n;v!=-1;v=parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    for(int x:path)cout<<x<<" ";
    cout<<endl;
    return 0;
    
}