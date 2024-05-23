#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=1e6+1;
vector<vector<ll>> dp(MAXN,vector<ll>(MAXN,0));
int main(){
    ll n,x;cin>>n>>x;
    vector<ll>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i && 2*coins[j]>=i){
                dp[i]=(dp[i]+dp[i-coins[j]])%MOD;
            }
        }
    }
    //cout<<dp[x]<<endl;
    for(int i=0;i<=x;i++)cout<<i<<" ";
    cout<<endl; 
    for(int i=0;i<=x;i++)cout<<dp[i]<<" ";
    cout<<endl;
    return 0;
}
