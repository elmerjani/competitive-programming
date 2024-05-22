#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1;
vector<int> adj[MAXN];
vector<int> parent(MAXN,-1);
int maxdist=0;
int dfs(int start,int par){
    vector<int> distances;
    for(int x:adj[start]){
        if(x==par)continue;
        parent[x]=start;
        distances.push_back(dfs(x,start)+1);
    }
    int n=distances.size();
    if(n==0)return 0;
    else if(n==1){
        if(distances[0]>maxdist)maxdist=distances[0];
        return distances[0];
    }
    else{
        sort(distances.begin(),distances.end());
        if(distances[n-1]+distances[n-2]>maxdist)maxdist=distances[n-1]+distances[n-2];
        return distances[n-1];
    }
}

int main(){
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int x=dfs(1,-1);
    cout<<maxdist<<endl;
    return 0;



}