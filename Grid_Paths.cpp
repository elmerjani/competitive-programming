#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e3;
vector<string> grid(MAXN);
vector<vector<ll>> dp(MAXN,vector<ll>(MAXN,0));
ll MOD=1e9+7;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    
    for(int i=0;i<n;i++){
        if(grid[i][0]=='.')dp[i][0]=1;
        else break;
    }
    for(int j=0;j<n;j++){
        if(grid[0][j]=='.')dp[0][j]=1;
        else break;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]=='*')dp[i][j]=0;
            else{
                
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
                
            }
            
        }
    }
    cout<<dp[n-1][n-1]<<"\n";
    

}