#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3;
const int INF=20;
vector<string> grid(MAXN);
vector<vector<pair<int,int>>> parent(MAXN,vector<pair<int,int>>(MAXN,{-1,-1})); 
vector<vector<int>> timer(MAXN,vector<int>(MAXN,INF));
vector<vector<bool>> used(MAXN,vector<bool>(MAXN,false));
int sort_i=-1,sort_j=-1;
void bfs_Monster(int i,int j,int n,int m ){
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(MAXN,vector<bool>(MAXN,false));
    visited[i][j]=true;
    timer[i][j]=0;
    q.push({i,j});
    while(!q.empty()){
        auto p=q.front();q.pop();
        int x=p.first;
        int y=p.second;
        int time=timer[x][y]+1;
        vector<pair<int,int>> voisins={{x+1,y},{x-1,y},{x,y+1},{x,y-1}};
        for(auto voisin:voisins){
                int nx=voisin.first;
                int ny=voisin.second;
                if(nx<0||nx>=n||ny<0||ny>=m)continue;
                if(visited[nx][ny])continue;
                if(grid[nx][ny]=='#')continue;
                visited[nx][ny]=true;
                timer[nx][ny]=min(timer[nx][ny],time);
                q.push({nx,ny});
            
        }
        

    }
}
bool dfs_char(int i,int j ,int n,int m,int time){
    if((i==0 ||j==0 ||i==n-1 || j==m-1) && time<timer[i][j]){
        sort_i=i;
        sort_j=j;
        return true;
    }
    used[i][j]=true;
    vector<pair<int,int>> voisins={{i+1,j},{i-1,j},{i,j+1},{i,j-1}};
    for(auto voisin:voisins){
        int nx=voisin.first;
        int ny=voisin.second;
        if(used[nx][ny]||grid[nx][ny]=='#'||timer[nx][ny]<=time+1)continue;
        parent[nx][ny]={i,j};
        if(dfs_char(nx,ny,n,m,time+1))return true;
        

    }
    return false;

    
}
int main(){
    int n,m;cin>>n>>m;
    pair<int,int> start;
    vector<pair<int,int>> monsters;
    for(int i=0;i<n;i++){
        cin>>grid[i];
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M'){
                monsters.push_back({i,j});
            }
            if(grid[i][j]=='A'){
                start={i,j};
            }

        }
    }
    for(auto monster:monsters){
        bfs_Monster(monster.first,monster.second,n,m);
    }
    if(dfs_char(start.first,start.second,n,m,0)){
        cout<<"YES"<<"\n";
        vector<pair<int,int>> pth;
        for(pair<int,int> p={sort_i,sort_j};p.first!=-1;p=parent[p.first][p.second]){
            pth.push_back(p);
        }
        cout<<pth.size()-1<<"\n";
        reverse(pth.begin(),pth.end());
        for(int i=1;i<pth.size();i++){
            if(pth[i].first==pth[i-1].first){
                if(pth[i].second>pth[i-1].second)cout<<"R";
                else cout<<"L";
            }
            else{
                if(pth[i].first>pth[i-1].first)cout<<"D";
                else cout<<"U";
            }
        }
        cout<<"\n";
        return 0;
    }
    cout<<"NO"<<"\n";
    
    

}
