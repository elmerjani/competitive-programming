#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
vector<vector<ll>> multiply(vector<vector<ll>> a,vector<vector<ll>> b,ll mod){
    int n=a.size();
    vector<vector<ll>> ans(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return ans;

}
vector<vector<ll>> power(vector<vector<ll>> a,ll n,ll mod){
    int m=a.size();
    vector<vector<ll>> ans(m,vector<ll>(m));
    if(n==0){
        for(int i=0;i<m;i++){
            ans[i][i]=1;
        }
        return ans;
    }
    ans=power(a,n/2,mod);
    if(n%2==0)return multiply(ans,ans,mod);
    else return multiply(multiply(ans,ans,mod),a,mod);
}
ll fibo(ll n,ll mod){
    vector<vector<ll>> tmp={{1,1},{1,0}};
    vector<vector<ll>> ans=power(tmp,n,mod);
    return ans[0][1];

}
int main(){
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        cout<<(MOD+fibo(m+2,MOD)-fibo(n+1,MOD))%MOD<<"\n";
    }


}