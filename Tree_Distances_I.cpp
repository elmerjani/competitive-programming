#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1;
vector<int> adj[MAXN];
vector<int> parent(MAXN,-1);

int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

}