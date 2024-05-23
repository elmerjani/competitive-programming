#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k=1;
    vector<ll> ors;
    ors.push_back(a[0]);
    for(int i=1;i<n;i++ ){
        if(k==1){
            if(a[i]!=ors.back()){
                k++;
                ll tmp=ors.back();
                ors.pop();
                ors.push_back(tmp|a[i]);
                ors.push_back(a[i]);
            }
        }
        else if(k==2){
            ll tmp=ors.back();
            ors.pop();
            ll ans=a[i]|tmp;
            
            if(ans==ors.back()){
                ors.push_back(ans);
                ors.push_back(a[i]);

            }
            else{
                k++;
                ll tmp2=ors.back()|a[i];
                ors.pop();
                ors.push_back(tmp2);
                ors.push_back(ans);
                ors.push_back(a[i]);
            }
        }
        else {
            ll tmp=ors.back();
            ors.pop();
            ll tmp2=ors.back();
            ors.pop();
            ll ans=a[i]|tmp2;
            if(ans==ors.back()){
                ors.push_back(ans);
                ors.push_back(a[i]);
            }
            else{
                k++;
                ll tmp2=ors.back()|a[i];
                ors.pop();
                ors.push_back(tmp2);
                ors.push_back(ans);
                ors.push_back(a[i]);
            }
        }

        

    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    

}