#include <bits/stdc++.h>
using namespace std;
const int MAXN=200;
vector<int>  adj[MAXN];
vector<int> color(MAXN,-1);
bool is_bipartite(int n){
    bool is_bipartite=true;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            color[i]=0;
            q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u]){
                if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
                else if(color[v]==color[u]){
                    is_bipartite=false;
                    break;
                }
            }
        }
    }
    return is_bipartite;

}
int main(){
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]>s[j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    if(is_bipartite(n)){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<color[i];
        }
    }
    else cout<<"NO"<<"\n";

}