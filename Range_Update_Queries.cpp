#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int main(){
    ll n,q;cin>>n>>q;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    while(__builtin_popcount(n)!=1){
        a.push_back(0);
        n++;
    }
    
    
}