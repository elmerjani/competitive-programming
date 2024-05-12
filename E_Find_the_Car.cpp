#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;cin>>t;
    while(t--){
        ll n,k,q;
        cin>>n>>k>>q;
        set<ll> s;
        unordered_map<ll,ll> time;
        time[0]=0;
        s.insert(0);
        vector<ll> a(k);
        for(int i=0;i<k;i++){
            cin>>a[i];
            s.insert(a[i]);
        }
        for(int i=0;i<k;i++){
           ll bi;cin>>bi;
           time[a[i]]=bi;
        }
        while(q--){
            ll d;
            cin>>d;
            auto it=s.find(d);
            if(it==s.end()){
                it=s.upper_bound(d);
                auto high=it;
                it=prev(it);
                double ti=time[*it]+(time[*high]-time[*it])*(d-*it)/(*high-*it);
                //cout<<ti<<" ";
                //if(ti-(int)ti>0.5)cout<<(int)ti +1<<" ";
                cout<<(int)ti<<" ";

            }
            else{
                cout<<time[*it]<<" ";

            }
            

        }
        cout<<endl;
    }

}