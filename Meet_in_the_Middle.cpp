#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void search(ll &x,ll &sum,ll &n,ll k,ll &count,vector<ll> &a){
    //cout<<k<<" "<<sum<<" "<<x<<"\n";
    if(n==k){
        
        if(sum==x)count++;
        return ;
        
    }
    if(sum>x)return;
    
    search(x,sum,n,k+1,count,a);
    sum+=a[k];
    search(x,sum,n,k+1,count,a);
    sum-=a[k];


}
int main(){
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll count=0;
    ll sum=0;
    search(x,sum,n,0,count,a);
    cout<<count<<endl;
    //return 0;
    

}