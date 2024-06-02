#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1;
vector<int> adj[MAXN];
vector<bool> visited(MAXN,false);
vector<int> height(MAXN), euler, first(MAXN);
void dfs(int start=1,int h=0){
    visited[start]=true;
    height[start]=h;
    first[start]=euler.size();
    euler.push_back(start);
    for(int x:adj[start]){
        if(!visited[x]){
            dfs(x,h+1);
            euler.push_back(start);
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=2;i<=n;i++){
        int boss;cin>>boss;
        adj[boss].push_back(i);
    }
    
    dfs();
    int m=euler.size();
    int log[m+1];
    log[1]=0;
    for(int i=2;i<=m;i++){
        log[i]=log[i/2]+1;
    }
    
    int st[m][log[m]+1];
    int st_index[m][log[m]+1];
    for(int i=0;i<m;i++){
        st_index[i][0]=i;
        //st[i][0]=height[euler[i]];
    }
    for(int k=1;k<=log[m];k++){
        for(int i=0;i+(1<<k)-1<m;i++){
            st_index[i][k]=height[euler[st_index[i][k-1]]]>height[euler[st_index[i+(1<<(k-1))][k-1]]]?st_index[i+(1<<(k-1))][k-1]:st_index[i][k-1];
            //st[i][k]=min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
        }
    }
    
    while(q--){
        int left,right;cin>>left>>right;
        int l=min(first[left],first[right]);
        int r=max(first[left],first[right]);

        int h=r-l+1;
        int k=log[h];
        int ans=height[euler[st_index[l][k]]]<height[euler[st_index[r-(1<<k)+1][k]]]?st_index[l][k]:st_index[r-(1<<k)+1][k];
        cout<<euler[ans]<<"\n";

    }
    


}