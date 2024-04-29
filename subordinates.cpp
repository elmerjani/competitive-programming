#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
vector<int> adj[MAXN];
int sub[MAXN];
void dfs(int n){
    sub[n]=1;
    for(int i=0;i<adj[n].size();i++){
        int v=adj[n][i];
        dfs(v);
        sub[n]+=sub[v];
    }
   
}


int main(){
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        int boss;cin>>boss;
        adj[boss].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<sub[i]-1<<" ";
    }
    cout<<'\n';
}