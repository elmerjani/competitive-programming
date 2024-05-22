#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=1e6+1;
vector<ll> dp(MAXN,0);
int main(){
    ll n,x;cin>>n>>x;
    vector<ll>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                dp[i]=(dp[i]+dp[i-coins[j]])%MOD;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}
