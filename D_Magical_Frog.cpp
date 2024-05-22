#include <bits/stdc++.h>
using namespace std;
long long MOD=1e9+7;
typedef long long ll;
vector<vector<long long>> multiple(vector<vector<long long>> a,vector<vector<long long>> b){
    int n=a.size();
    vector<vector<long long>> c(n,vector<long long>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            long long sum=0;
            for(int k=0;k<n;k++){
                sum=(sum+a[i][k]*b[k][j])%MOD;
            }
            c[i][j]=sum;
        }
    }
    return c;
}
vector<vector<long long>> binpow(vector<vector<long long>> a,int n){
    int m=a.size();
    if(n==0){
        vector<vector<long long>> c(m,vector<long long>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)c[i][j]=1;
                else c[i][j]=0;
            }
        }
        return c;
    }
    else{
        vector<vector<long long>> b=binpow(a,n/2);
        if(n%2==0){
            return multiple(b,b);
        }
        else{
            return multiple(multiple(b,b),a);
        }
    }
}

int main(){
    ll n,k;cin>>n>>k;
    vector<vector<long long>> a(k,vector<long long>(k));
    for(int i=0;i<k-1;i++){
        for(int j=0;j<k;j++){
            if(i+1==j)a[i][j]=1;
            else a[i][j]=0;
        }
    }
    for(int i=0;i<k;i++)a[k-1][i]=1;
    vector<vector<long long>> b=binpow(a,n);
    cout<<b[k-1][k-1]<<"\n";
}