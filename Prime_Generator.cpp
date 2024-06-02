#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
vector<bool> isPrime(MAXN,true);
vector<int> primes;
void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int p=2;p*p<=MAXN;p++){
        if(isPrime[p]){
            //primes.push_back(p);
            for(int i=p*p;i<=MAXN;i+=p){
                isPrime[i]=false;
            }
        }
    }
    for(int p=2;p<=MAXN;p++){
        if(isPrime[p]){
            primes.push_back(p);
        }
    }
}
bool is_prime(int n){
    if(n==1)return false;
    for(int x:primes){
        if(x>n/x)break;
        if(n%x==0)return false;
    }
    return true;
}

int main(){
    sieve();
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        for(int i=n;i<=m;i++){
            if(is_prime(i)){
                cout<<i<<endl;
                //break;
            }
        }
        cout<<endl;

    }
}