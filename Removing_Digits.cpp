#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
const int INF=1e9;
vector<int> dp(MAXN,INF);
int main(){
    int n;cin>>n;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int x=i;
        vector<int> digits;
        while(x>0){
            digits.push_back(x%10);
            x/=10;
        }
        
        for(int digit:digits){
            if(dp[i-digit]!=INF){
                dp[i]=min(dp[i],dp[i-digit]+1);
            }

        }
    }
    cout<<dp[n]<<endl;
    return 0;
}