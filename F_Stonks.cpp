#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    set<pair<int,pair<ll,string>>> feqSomme;
    map<string,pair<int,ll>> freq;
    int q;cin>>q;
    while(q--){
        int t;cin>>t;
        if(t==1){
            string stock;cin>>stock;
            reverse(stock.begin(),stock.end());
            ll prix;cin>>prix;
            freq[stock].first++;
            freq[stock].second+=prix;
            feqSomme.insert({freq[stock].first,{freq[stock].second,stock}});
            auto it=feqSomme.find({freq[stock].first-1,{freq[stock].second-prix,stock}});
            if(it!=feqSomme.end())feqSomme.erase(it);
            

        }
        else{
            string s=(*feqSomme.rbegin()).second.second;
            reverse(s.begin(),s.end());
            cout<<s<<"\n";

        }
    }
}