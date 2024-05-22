#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int  x,y;cin>>x>>y;
        int ans=y/2;
        if(y%2==0){
            x-=(ans*7);
            if(x<=0){
                cout<<ans<<endl;
                continue;
            }
            int anss=x/15;
            if(x%15==0){
                cout<<ans+anss<<"\n";
                continue;
            }
            cout<<ans+anss+1<<"\n";
            
        }
        else {
            x-=(ans*7);
            x-=11;
            ans++;
            if(x<=0){
                cout<<ans<<endl;
                continue;
            }
            int anss=x/15;
            if(x%15==0){
                cout<<ans+anss<<"\n";
                continue;
            }
            cout<<ans+anss+1<<"\n";
            

        }
        
    }
}