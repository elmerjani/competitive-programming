#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        bool can=false;
        for(int m=1;m<=n;m++){
            int ans=(m*(m-1))/2+((n-m)*(n-m-1))/2;
            if(ans==k){
                can=true;
                cout<<"YES"<<"\n";
                for(int i=1;i<=m;i++)cout<<1<<" ";
                for(int i=m+1;i<=n;i++)cout<<-1<<" ";
                break;

            }
        }
        if(can==false)cout<<"NO";
        cout<<"\n";

    }
}