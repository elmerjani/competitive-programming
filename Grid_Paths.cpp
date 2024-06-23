#include <bits/stdc++.h>
using namespace std;
int ans=0;
void search(int i,int j,vector<vector<bool>> visited, string path,int k){
    //cout<<k<<"\n";
    if(i<0||i>6||j<0||j>6||visited[i][j])return ;
    visited[i][j]=true;
    if(k==48 && i==6&&j==0){
        ans++;
        return ;
    }
    if(path[k]=='D'||path[k]=='?')search(i+1,j,visited,path,k+1);
    if(path[k]=='U'||path[k]=='?')search(i-1,j,visited,path,k+1);
    if(path[k]=='R'||path[k]=='?')search(i,j+1,visited,path,k+1);
    if(path[k]=='L'||path[k]=='?')search(i,j-1,visited,path,k+1);

}
int main(){
    string path;cin>>path;
    vector<vector<bool>> visited(7,vector<bool>(7,false));
    search(0,0,visited,path,0);
    cout<<ans<<endl;
    return 0;

}
?????????????????DLDRRURDDLLLL?URULURRUULDLL????