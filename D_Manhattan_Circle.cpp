#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<string> grid(n);
        for(int i=0;i<n;i++)cin>>grid[i];
        int row=0,column=0;
        bool found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#'){
                    row=i;
                    column=j;
                    found=true;
                    break;
                    
                }
            }
            if(found)break;
        }
        
        int rowcount=1,columncount=1;
        for(int i=row+1;i<n;i++){
            if(grid[i][column]=='.')break;
            rowcount++;
        }
        for(int j=column+1;j<m;j++){
            if(grid[row][j]=='.')break;
            columncount++;
        }
        cout<<row+(rowcount-1)/2+1<<" "<<column+(columncount-1)/2+1<<"\n";
        
    }
}