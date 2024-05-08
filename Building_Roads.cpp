#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MAXN=100001;
ll count=0;
vector<int> v;
vector<int> adj[MAXN];
vector<bool> visited(MAXN,false);
void dfs(int u){
    if(visited[u]){
        count++;
        v.push_back(i);
        return ;
    }
    for(int j:adj[i]){
        dfs(j);
    }
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    
    for(int i=0;i<n;i++){
        if(visited[i]){
            count++;
            v.push_back(i);
        }
        else{
            visited[i]=true;
            for(int j:adj[i]){
                dfs(j);
            }
        }
    }


}