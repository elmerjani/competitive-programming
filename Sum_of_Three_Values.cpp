#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,x;cin>>n>>x;
    vector<pair<ll,ll>> a;
    for(ll i=0;i<n;i++){
        ll ai;cin>>ai;
        a.push_back(pair<ll,ll>(ai,i+1));
    }
    sort(a.begin(),a.end());
    
   
   bool exist =false;
    for(int i=0;i<n;i++){
        int left=i+1,right=n-1;
        while(left<right){
            ll sum=a[i].first+a[right].first+a[left].first;
            if(sum==x){
                cout<<a[i].second<<" "<<a[right].second<<" "<<a[left].second<<"\n";
                exist=true;
                break;
            }
            else{
                if(sum<x){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        if(exist){
            break;
        }
    }
    if(!exist)cout<<"IMPOSSIBLE"<<"\n";


}