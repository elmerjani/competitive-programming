#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b){
    ll n=a.size();
    vector<vector<ll>> ans(n,vector<ll>(n));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return ans;
}
vector<vector<ll>> power(vector<vector<ll>> a,ll n){
    if(n==0){
        vector<vector<ll>> ans(a.size(),vector<ll>(a.size()));
        for(ll i=0;i<a.size();i++){
            ans[i][i]=1;
        }
        return ans;
    }
    vector<vector<ll>> ans=power(a,n/2);
    if(n%2==0){
        return multiply(ans,ans);
    }
    return multiply(multiply(a,ans),ans);

    
}
int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> tmp={{0,1,0,0,0,0},
                            {0,0,1,0,0,0},
                            {0,0,0,1,0,0},
                            {0,0,0,0,1,0},
                            {0,0,0,0,0,1},
                            {1,1,1,1,1,1}};
    vector<vector<ll>> ans=power(tmp,n);
    cout<<ans[5][5]<<"\n";
    /*for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }*/
}