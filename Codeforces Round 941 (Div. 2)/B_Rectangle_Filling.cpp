#include <bits/stdc++.h>
using namespace std;
bool rowsame(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]!=s[0])return false;
    }
    return true;
}
bool colsame(string grid[],int n,int j){
    for(int i=0;i<n;i++){
        if(grid[i][j]!=grid[0][j])return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string path[n]={};
        for(int i=0;i<n;i++){
            cin>>path[i];
        }
        if(n==1 && m==1)cout<<"YES";
        else {
            if(n==1){
                if(path[0][0]==path[0][m-1])cout<<"Yes";
                else cout<<"No";
            }

            
            else if(m==1){
                if(path[0][0]==path[n-1][0])cout<<"Yes";
                else cout<<"No";

            }
            else{
                if(rowsame(path[0])&&rowsame(path[n-1])){
                    if(path[0][0]==path[n-1][0])cout<<"YES";
                    else cout<<"NO";
                }
                else if(rowsame(path[0])||rowsame(path[n-1]))cout<<"YES";
                else{
                    
                        if(colsame(path,n,0)&& colsame(path,n,m-1)){
                            if(path[0][0]==path[0][m-1])cout<<"YES";
                            else cout<<"NO";
                        }
                        else{
                            cout<<"YES";
                        }
                    }
                }
                

            }
            cout<<"\n";
        }


        
    }
    

