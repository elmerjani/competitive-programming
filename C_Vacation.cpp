#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    for(int i=1;i<=n;i++){
        int ai,bi,ci;
        cin>>ai>>bi>>ci;
        dp[i][0]=ai+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=bi+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=ci+max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<"\n";
}