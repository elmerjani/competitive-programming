#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        unordered_map<int,int> mp;
        ll count =0;
        for(int i=0;i<n;i++){
            int ai;cin>>ai;
            count+=mp[ai];
            if(ai==1)count+=mp[2];
            else if(ai==2)count+=mp[1];
            mp[ai]++;
        }
        cout<<count<<"\n";
    }
}