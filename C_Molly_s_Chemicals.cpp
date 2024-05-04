#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MAXN=1e15;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;cin>>n>>k;
    ll sum[n+1];
    sum[0]=0;
    ll s=0;
    for(int i=1;i<=n;i++){
        ll ai;cin>>ai;
        s+=ai;
        sum[i]=s;
    }
    if(k==1||k==-1){
        map<ll,ll> mp;
        ll count=0;
        for(int i=0;i<=n;i++){
            count+=(mp[sum[i]-1]+(k==-1?mp[sum[i]+1]:0));
            
            mp[sum[i]]++;
            
        }
        cout<<count<<endl;
        return 0;
    }
    
    ll count=0;
    ll l=1;
    while(abs(l)<=MAXN){
        
        map<ll,ll> mp;
        ll innercount=0;
        for(int i=0;i<=n;i++){
            innercount+=(mp[sum[i]-l]);
            mp[sum[i]]++;
        }
        l*=k;
        count+=innercount;
    }
    cout<<count<<endl;
    return 0;

    
    
}