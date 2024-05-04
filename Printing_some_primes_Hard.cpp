#include <bits/stdc++.h>
using namespace std;
int main(){
    int maxn=1e9;
    bitset<1000000001> bits;
    bits.set();
    
    bits[0]=false;
    bits[1]=false;
    for(int i=3;i*i<=maxn;i+=2){
        if(bits[i]==true){
            for(int j=i*i;j<=maxn;j+=i)bits[j]=false;
        }
    }
    
    cout<<2<<"\n";
    int k=2;
    for(int i=3;i<=maxn;i+=2){
        if(bits[i]==true){
            if(k==1){
                cout<<i<<"\n";
               
            }
             k=(k+1)%500;
        }
    }
}