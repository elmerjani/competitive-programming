#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int aiiii(int ai){
    if(ai<4)return 0;
    int aii=ai%2==0?ai:ai-1;
    aii=aii%4==0?aii:aii-2;
    return aii;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        unordered_map<int,multiset<int>> mp;
        for(int i=0;i<n;i++){
            int ai;cin>>ai;
            a[i]=ai;
            int aiii=aiiii(ai);
            mp[aiii].insert(ai);

        }
        for(int i=0;i<n;i++){
            int ai=aiiii(a[i]);
            if(mp[ai].size()==1){
                cout<<*mp[ai].begin()<<" ";
                mp[ai].erase(mp[ai].begin());
            }
            else{
                auto it=mp[ai].begin();
                cout<<(*it)<<" ";
                mp[ai].erase(it);
            }
        }
        cout<<"\n";

    }
}