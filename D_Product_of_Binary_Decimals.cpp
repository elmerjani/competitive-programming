#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MAXN=1e5;
void search( ll k,vector<ll> &ans,ll somme){
    if(k==6){
        ans.push_back(somme);
        return ;

    }
    search(k+1,ans,somme);
    somme+=(ll)pow(10,k);
    search(k+1,ans,somme);
    somme-=(ll)pow(10,k);
}
int main(){
    vector<bool> bin(MAXN+1,false);
    vector<ll> ans;
    set<ll> binary;
    search(0,ans,0);
    //sort(ans.begin(),ans.end());
    int m=ans.size();
    for(int i=0;i<m;i++){
        if(ans[i]>1 &&ans[i]<=MAXN)binary.insert(ans[i]);    
    }
    auto it=binary.begin();
    while(it!=binary.end()){
        bin[*it]=true;
        auto itt=it;
        while(itt!=binary.end()){
            if((*it)*(*itt)>MAXN)break;
            binary.insert((*it)*(*itt));
            itt++;
        }
        it++;
    }
    bin[1]=true;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(bin[n])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    

       
    

    
    

}