#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e14;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll a[n],b[n+1];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<=n;i++)cin>>b[i];
        ll count=0;
        ll lastont=INF;
        for(int i=0;i<n;i++){
            count+=abs(a[i]-b[i]);
            ll maxi=max(a[i],b[i]),mini=min(a[i],b[i]);
            if(b[n]<=maxi&&b[n]>=mini)lastont=0;
            else if(b[n]>maxi)lastont=min(lastont,b[n]-maxi);
            else if(b[n]<mini)lastont=min(lastont,mini-b[n]);
            
        }
        count+=(lastont+1);
        cout<<count<<"\n";


    }
}