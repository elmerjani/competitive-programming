#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
void dijkstra(int start,vector<int> &dist,vector<pair<int,int>> adj[]){
    dist[start]=0;
    set<pair<int,int>> q;
    q.insert({0,start});
    while(!q.empty()){
        int v=(*q.begin()).second;
        q.erase(q.begin());
        for(auto  p:adj[v]){
            int to=p.first;
            int len=p.second;
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
        int n;cin>>n;
        vector<pair<int,int>> adj[n+1];
        unordered_map<string,int> mp;
        for(int i=1;i<=n;i++){
            string s;cin>>s;
            mp[s]=i;
            int m;cin>>m;
            for(int j=0;j<m;j++){
                int to,len;cin>>to>>len;
                adj[i].push_back({to,len});
            }
        }
        int r;cin>>r;
        while(r--){
            string s1,s2;cin>>s1>>s2;
            vector<int> dist(n+1,INF);
            dijkstra(mp[s1],dist,adj);
            cout<<dist[mp[s2]]<<endl;
        }

    }
    

}