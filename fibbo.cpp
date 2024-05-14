#include <bits/stdc++.h>
using namespace std;
vector<int> fibo;
vector<int> powers;
const int MAXN=1e5;
const int MOD=76; 
int main(){
    fibo.push_back(0);
    fibo.push_back(1);
    for(int i=2;i<76;i++){
        fibo.push_back((fibo[i-1]+fibo[i-2])%37);
    }
    powers.push_back(1);
    for(int i=1;i<=MAXN;i++){
        powers.push_back((10*powers[i-1])%MOD);
    }
    int t;cin>>t;
    while(t--){
        string integer;cin>>integer;
        int n=integer.size();
        int count=0;
        for(int i=0;i<n;i++){
            count =(count+((integer[i]-'0')*powers[n-i-1])%MOD)%MOD;
        }
        cout<<fibo[count]<<"\n";
    }
    
    
    
}