#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
vector<int> adj[MAXN];
vector<bool> used(MAXN,false);
vector<int> p(MAXN);
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    p[1]=-1;
    used[1]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int u:adj[v]){
            if(!used[u]){
                q.push(u);
                p[u]=v;
                used[u]=true;
            }
        }
    }
    if(used[n]){
        vector<int> path;
        for(int u=n;u!=-1;u=p[u]){
            path.push_back(u);
        }
        cout<<path.size()<<endl;
        reverse(path.begin(),path.end());
        for(int x:path)cout<<x<<" ";

    }
    else{
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }

}