#include <bits/stdc++.h>
using namespace std;
long long MOD=1e9+7;
vector<vector<long long>> multiple(vector<vector<long long>> a,vector<vector<long long>> b){
    vector<vector<long long>> c(3,vector<long long>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            long long sum=0;
            for(int k=0;k<3;k++){
                sum=(sum+a[i][k]*b[k][j])%MOD;
            }
            c[i][j]=sum;
        }
    }
    return c;
}
vector<vector<long long>> binpow(vector<vector<long long>> a,int n){
    if(n==0){
        vector<vector<long long>> c(3,vector<long long>(3));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
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
    int n;
    cin>>n;
    vector<vector<long long >> tribo={{0,1,0},{0,0,1},{1,1,1}};
    vector<vector<long long >> ans=binpow(tribo,n);
    cout<<ans[1][2]<<"\n";
}