#include <bits/stdc++.h>
using namespace std;
vector<int> ass(int x){
    vector<int> ans;
    while(x>0){
        ans.push_back(x%2);
        x/=2;
    }
    while(ans.size()<32)ans.push_back(0);
    return ans;
}
int main(){
    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        vector<int> ans=ass(x);
        
        //cout<<32<<"\n";
        //for(int i=0;i<32;i++)cout<<ans[i]<<" ";
        //cout<<"\n";
        
        int i=0;
        while( i<32){
            if(ans[i]==0||i==31||ans[i+1]==0){
                i++;
                continue;
            }
            ans[i]=-1;
            i++;
            while(i<30 && ans[i+1]==1){
                ans[i]=0;
                i++;
            }
            ans[i]=0;
            ans[i+1]=1;
            i++;
            
            
        }
        int count=32;
        while(ans[count-1]==0)count--;
        cout<<count<<"\n";
        for(int j=0;j<count;j++)cout<<ans[j]<<" ";
        cout<<"\n";
        
    }
}