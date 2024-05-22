#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    vector<int> dp(n+1);
    dp[1]=0;dp[2]=abs(h[2]-h[1]);
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-2]+abs(h[i]-h[i-2]),dp[i-1]+abs(h[i]-h[i-1]));

    }
    //for(int x:dp)cout<<x<<" ";
    cout<<dp[n]<<"\n";
    return 0;
}