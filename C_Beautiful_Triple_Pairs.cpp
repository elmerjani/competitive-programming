#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        unordered_map<string,ll> mp;
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll  counter=0;
        for(int i=0;i<n-2;i++){
            //pair<int,pair<int,int>>p={a[i],{a[i+1],a[i+2]}}, p1={0,{a[i+1],a[i+2]}},p2={a[i],{0,a[i+2]}},p3={a[i],{a[i+1],0}};
            string p=to_string(a[i])+","+to_string(a[i+1])+","+to_string(a[i+2]);
            string p1=to_string(a[i])+",0,"+to_string(a[i+2]);
            string p2="0,"+to_string(a[i+1])+","+to_string(a[i+2]);
            string p3=to_string(a[i])+","+to_string(a[i+1])+",0";
            counter+=mp[p1];
            counter+=mp[p2];
            counter+=mp[p3];
            counter-=mp[p];
            mp[p]+=3;
            mp[p1]++;
            mp[p2]++;
            mp[p3]++;
        }
        cout<<counter<<endl;
        
            
            
    }
        
        
}
