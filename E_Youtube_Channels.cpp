#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+1; 
vector<ll> mp(MAXN,0);
int main(){
    set<pair<ll,int>> st;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        st.insert({0,i});

    }
    while(q--){
        int type;cin>>type;
        if(type==1){
            ll x;int y;
            cin>>x>>y;
            ll val=mp[y];
            auto it=st.find({val,y});
            st.erase(it);
            mp[y]=x+val;
            st.insert({x+val,y});

        }
        else if(type==2){
            ll x;int y;
            cin>>x>>y;
            ll val=mp[y];
            auto it=st.find({val,y});
            
            st.erase(it);
            
            mp[y]=val-x;
            st.insert({val-x,y});

        }
        else if(type==3){
            ll val=(*st.rbegin()).first;
            cout<<(*st.lower_bound({val,1})).second;
            cout<<endl;



        }
        else{
            
            
            cout<<(*st.begin()).second;
            cout<<endl;

        }
    }
}