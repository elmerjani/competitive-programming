#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<2000000> can;

int main(){
    int n;cin>>n;
    can[0]=true;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        can=can|(can<<x);
    }
    ll i=0;
    while(can[i])i++;
    cout<<i<<endl;



}