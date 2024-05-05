#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
int main(){
    int n;cin>>n;
    ll dp[n][n];
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='*')dp[i][j]=0;
            else{
                if(i==0 || j==0)dp[i][j]=1;
                else{
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
                }
            }
            
        }
    }
    cout<<dp[n-1][n-1]<<"\n";

}