#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3;
string grid[MAXN];
vector<vector<bool>> visited;

int main(){
    int n,m;cin>>n>>m;
    int xa,ya,xb,yb;
    vector<vector<pair<int,int>>> p;
    for(int i=0;i<n;i++){
        cin>>grid[i];
        vector<bool> a(m,false);
        visited.push_back(a);
        vector<pair<int,int>> b(m);
        p.push_back(b);
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                xa=i;
                ya=j;
            }
            if(grid[i][j]=='B'){
                xb=i;
                yb=j;
            }
        }

    }
    queue<pair<int,int>> q;
 
      
           
                q.push({xa,ya});
                visited[xa][ya]=true;
                p[xa][ya]={-1,-1};
                while(!q.empty()){
                    pair<int,int> cur=q.front();
                    q.pop();
                    int x=cur.first;
                    int y=cur.second;
                    if(x-1>=0 &&!visited[x-1][y] && grid[x-1][y]!='#'){
                        q.push({x-1,y});
                        visited[x-1][y]=true;
                        p[x-1][y]={x,y};
                    }
                    if(x+1<n &&!visited[x+1][y] && grid[x+1][y]!='#'){
                        q.push({x+1,y});
                        visited[x+1][y]=true;
                        p[x+1][y]={x,y};
                    }
                    if(y-1>=0 &&!visited[x][y-1] && grid[x][y-1]!='#'){
                        q.push({x,y-1});
                        visited[x][y-1]=true;
                        p[x][y-1]={x,y};
                    }
                    if(y+1<m &&!visited[x][y+1] && grid[x][y+1]!='#'){
                        q.push({x,y+1});
                        visited[x][y+1]=true;
                        p[x][y+1]={x,y};
                    }
                }
                if(!visited[xb][yb]){
                    cout<<"NO"<<endl;
                    return 0;
                }
                vector<pair<int,int>> v;
                string path="";
                for(pair<int,int> u={xb,yb};u.first!=-1;u=p[u.first][u.second]){
                    v.push_back(u);
                }
                cout<<"YES"<<"\n";
                cout<<v.size()-1<<"\n";
                
                reverse(v.begin(),v.end());
                
                for(int i=1;i<v.size();i++){
                    if(v[i].first==v[i-1].first){
                        if(v[i].second>v[i-1].second)cout<<"R";
                        else cout<<"L";
                    }
                    else{
                        if(v[i].first>v[i-1].first)cout<<"D";
                        else cout<<"U";
                    }
                }
                cout<<"\n";
                return 0;
            
        
    

    
    
    
}
    

