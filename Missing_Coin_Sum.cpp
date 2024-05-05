#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll n;cin>>n;
    vector<ll> a(n);
    for(int  i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(a[0]!=1){
        cout<<1<<endl;
        return 0;
    }
    if(a[1]>2){
        cout<<2<<endl;
        return 0;
    }
    ll sum=a[0]+a[1];
    for(int i=2;i<n;i++){
        if(a[i]>sum+1){
            cout<<sum+1<<endl;
            return 0;
        }
        sum+=a[i];
    }
    cout<<sum+1<<endl;
    return 0;




}