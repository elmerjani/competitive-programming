#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e6+1;
vector<ll> primes;
vector<ll> freq(MAXN,0);
void sieve(){
    vector<bool> isPrime(MAXN,true);
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i*i<MAXN;i++){
        if(isPrime[i]){
            for(ll j=i*i;j<MAXN;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(ll i=2;i<MAXN;i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }

}
int  main(){
    sieve();
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll ai;
        cin>>ai;
        freq[ai]++;
    }
    ll ans=0;
    for(ll prime:primes){
        for()
    }

    
    
    
}