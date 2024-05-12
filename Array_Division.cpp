#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MAXN=2e14+1;
bool can(vector<ll> a,ll val,int k){
    int count=1;
    int n=a.size();
    ll t=0;
    for(int i=0;i<n;i++){
        if(t+a[i]<=val){
            t+=a[i];
        }
        else{
            count++;
            t=a[i];
        }
        if(count>k)return false;
    }
    return count<=k;
}
ll binSearch(vector<ll> a,int k,ll low,ll high){
    if(low==high)return low;
    ll mid=low+(high-low)/2;
    if(can(a,mid,k))return binSearch(a,k,low,mid);
    else return binSearch(a,k,mid+1,high);

}
int main(){
    int n,k;cin>>n>>k;
    ll maximum=0;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        ll ai;cin>>ai;
        a[i]=ai;
        maximum=max(ai,maximum);
    }
    cout<<binSearch(a,k,maximum,MAXN)<<"\n";
    
    
    
    

}