#include <bits/stdc++.h>
using namespace std;
int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,0);
        sort(costs.begin(),costs.end());
        vector<bool> has_trip(366,false);
        for(int x:days){
            has_trip[x]=true;
        }
        dp[1]=costs[0];
        for(int i=2;i<=365;i++){
            if(!has_trip[i])continue;
            else{
                dp[i]=costs[0];
                int somme=0;
                int j=i;
                while(j>=1 && i-j+1<=7){
                    
                    somme+=dp[j];
                    j--;
                }
                if(somme<costs[1]){
                    continue;
                    
                }
                else{
                    dp[j]=costs[1];
                    for(int k=j+1;k<=i;k++)dp[k]=0;
                    if(j==1)continue;
                    somme=0;
                    j=i;
                    while(j>=0 && i-j+1<=30 ){
                        somme+=dp[j];
                        j--;
                    }
                    if(somme<costs[2]){
                        continue;
                    }
                    else{
                        dp[j]=costs[2];
                        for(int k=j+1;k<=i;k++)dp[k]=0;
                    }
                    
                }
            }
        }
        int ans=0;
        for(int i=1;i<=365;i++){
            cout<<dp[i]<<"\n";
            ans+=dp[i];
        }
        return ans;
        
    }

int main(){
    vector<int> days={1,4,6,7,8,20};
    vector<int> costs={2,7,15};
    cout<<mincostTickets(days,costs)<<endl;
    return 0;

}