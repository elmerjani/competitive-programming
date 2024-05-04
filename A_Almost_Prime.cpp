#include <bits/stdc++.h>
using namespace std;
int MAXN=3000;
vector<int> sieve(){
    vector<int> primes;
    vector<bool> isPrime(MAXN+1,true);
    for(int i=2;i<=MAXN;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=i*i;j<=MAXN;j+=i){
                isPrime[j]=false;
            }
        }
    }
    return primes;
}
int main(){
    int n;cin>>n;
    int count=0;
    vector<int> primes=sieve();
    int k=primes.size();
    for(int i=6;i<=n;i++){
        int countprimes=0;
        for(int j=0;j<k;j++){
            if(primes[j]>i)break;
            if(i%primes[j]==0)countprimes++;
        }
        if(countprimes==2)count++;
    }
    cout<<count<<endl;
    return 0;
}