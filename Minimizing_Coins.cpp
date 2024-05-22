#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
const int INF=1e9;
vector<int> dp(MAXN,INF);
int main(){
    dp[0]=0;
    int n,x;cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    for(int i=1;i<=x;i++){
        for(int coin:coins){
            if(i-coin>=0&&dp[i-coin]!=INF){
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
    }
    if(dp[x]==INF)cout<<-1<<"\n";
    else cout<<dp[x]<<"\n";

}