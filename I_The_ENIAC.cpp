#include <bits/stdc++.h>
using namespace std;
const int MAXN=301;
typedef long long ll;
const ll INF=1e14;
vector<vector<ll>> dist(MAXN,vector<ll>(MAXN,INF));



int main(){
    int n,m,q;cin>>n>>m>>q;
   
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        dist[a][b]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        if(dist[a][b]==INF)cout<<"NO\n";
        else cout<<"YES"<<"\n";
    }
    
}