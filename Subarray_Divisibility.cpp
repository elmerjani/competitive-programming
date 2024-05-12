#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;cin>>n;
    ll sum[n+1];sum[0]=0;
    for(int i=1;i<=n;i++){
        ll ai;cin>>ai;
        sum[i]=sum[i-1]+ai;
    }
    unordered_map<int,int> mp;
    ll ans=0;
    for(int i=0;i<=n;i++){
        ans+=mp[(n+sum[i]%n)%n];
        mp[(n+sum[i]%n)%n]++;

    }
    cout<<ans<<endl;
    return 0;

}