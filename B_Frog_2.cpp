#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    vector<int> dp(n+1,INF);
    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j<=0)break;
            dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));

        }
        

    }
    //for(int x:dp)cout<<x<<" ";
    cout<<dp[n]<<"\n";
    return 0;
}