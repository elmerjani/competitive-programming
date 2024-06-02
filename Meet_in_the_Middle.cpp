#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> mp;
ll countt=0;
ll x;
void search(ll &sum,ll n,ll k,vector<ll> a){
    //cout<<k<<" "<<sum<<" "<<x<<"\n";
    if(n==k){
        
        mp[sum]++;
        return ;
        
    }
    //if(sum>x)return;
    
    search(sum,n,k+1,a);
    sum+=a[k];
    search(sum,n,k+1,a);
    sum-=a[k];


}
void searchb(ll &sum,ll n,ll k,vector<ll> b){
    //cout<<k<<" "<<sum<<" "<<x<<"\n";
    if(n==k){
        
        countt+=mp[x-sum];
        return ;
        
    }
    //if(sum>x)return;
    
    searchb(sum,n,k+1,b);
    sum+=b[k];
    searchb(sum,n,k+1,b);
    sum-=b[k];


}
int main(){
    ll n;cin>>n>>x;
    vector<ll> a,b;
    for(int i=0;i<n/2;i++){
        ll ai;cin>>ai;
        a.push_back(ai);
    }
    for(int i=n/2;i<n;i++){
        ll bi;cin>>bi;
        b.push_back(bi);
    }
    //countt=0;
    ll sum=0;
    search(sum,a.size(),0,a);
    sum=0;
    searchb(sum,b.size(),0,b);
    //for(auto u:mp){
      //  cout<<u.first<<" "<<u.second<<"\n";
    //}
    cout<<countt<<endl;
    //return 0;
    

}
//mp+sum=x