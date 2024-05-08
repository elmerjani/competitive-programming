#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,k;cin>>n>>k;
    ll sum[n+1];
    sum[0]=0;
    for(int i=1;i<=n;i++){
        ll ai;cin>>ai;
        sum[i]=sum[i-1]+ai;
    }
    int t=n-k+1;
    ll ans=0;
    map<
    //sum[right]-sum[left-1]>=ans &&right-left
    

}