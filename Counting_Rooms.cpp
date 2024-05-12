#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3;
string grid[MAXN];
vector<vector<bool>> visited;
void dfs(int i,int j,int n,int m){
    visited[i][j]=true;
    //cout<<i<<j<<"\n";
    if(i>0 && grid[i-1][j]=='.' && !visited[i-1][j])dfs(i-1,j,n,m);
    if(i<n-1 &&grid[i+1][j]=='.'&&!visited[i+1][j])dfs(i+1,j,n,m);
    if(j>0 && grid[i][j-1]=='.' && !visited[i][j-1])dfs(i,j-1,n,m);
    if(j<m-1 && grid[i][j+1]=='.'&& !visited[i][j+1])dfs(i,j+1,n,m);
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    
    for(int  i=0;i<n;i++){
        vector<bool> a;
        for(int j=0;j<m;j++){
            a.push_back(false);
            
        }
        visited.push_back(a);
        
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]=='.'){
                count++;
                dfs(i,j,n,m);
            }
        }
    }
    cout<<count<<endl;

}