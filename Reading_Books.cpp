#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;cin>>n;
    ll sum=0;
    ll max=0;
    for(int i=0;i<n;i++){
        ll ti;cin>>ti;
        sum+=ti;
        if(ti>max)max=ti;

    }
    sum-=max;
    if(sum>=max)cout<<(sum+max)<<"\n";
    else cout<<2*max<<"\n";
}