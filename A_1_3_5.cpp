#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=2;
        for(int i=0;i<=20;i++){
            for(int j=0;j<=35;j++){
                int m=5*i+3*j;
                if(n-m>=0 && n-m<=ans)ans=n-m;
            }
        }
        cout<<ans<<endl;
    }
}