#include <bits/stdc++.h>
using namespace std;
const int MAXN=4e3+1;
vector<int> adj[MAXN];
vector<int> color(MAXN,-1);
int isBipartite(int start){
    queue<int> q;
    q.push(start);
    color[start]=0;
    int ones=0,zeros=1;
    while(!q.empty()){
        int node=q.front();q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(color[it]==0){
                    zeros++;
                }
                else if(color[it]==1){
                    ones++;
                }
                q.push(it);
            }
            else if(color[it]==color[node]){
                return -1;
            }
        }
    }
    return abs(ones-zeros);

}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            int x=isBipartite(i);
            if(x==-1){
                cout<<-1<<"\n";
                return 0;
            }
            ans=abs(ans-x);
        }
    }
    cout<<ans<<"\n";
    return 0;


}