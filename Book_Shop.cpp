#include <bits/stdc++.h>
using namespace std;
int main(){
    
    int n,x;cin>>n>>x;
    int price[n],pages[n];
    for(int i=0;i<n;i++)cin>>price[i];
    for(int i=0;i<n;i++)cin>>pages[i];
    vector<int> maximum(x+1,0);
    vector<vector<bool>> pile(x+1,vector<bool>(n,false));
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=price[j] && pile[i-price[j]][j]==false){
                if(pages[j]+maximum[i-price[j]]>maximum[i]){

                    maximum[i]=pages[j]+maximum[i-price[j]];
                    vector<bool> v=pile[i-price[j]];
                    v[j]=true;
                    pile[i]=v;
                }
            }
        }
        
    }
    int ans=0;
    for(int i=0;i<=x;i++)ans=max(ans,maximum[i]);
    cout<<ans<<endl;
    return 0;
}