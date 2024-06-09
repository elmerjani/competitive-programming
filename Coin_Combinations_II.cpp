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
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(coins[i]<=j){
                dp[j]=(dp[j]+dp[j-coins[i]])%MOD;
            }
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}
