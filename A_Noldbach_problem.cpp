#include <bits/stdc++.h>
using namespace std;


vector<int> sieve(int MAXN){
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
bool binSearch(vector<int> primes,int n){
    int l=0,r=primes.size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(primes[mid]==n)return true;
        else if(primes[mid]<n)l=mid+1;
        else r=mid-1;
    }
    return false;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int> primes=sieve(n);
    int count=0;
    int m=primes.size();
    for(int i=0;i<m-1;i++){
        if(primes[i]+primes[i+1]+1>primes[m-1])break;
        if(binSearch(primes,primes[i]+primes[i+1]+1))count++;
        if(count>=k)break;

    }
    if(count>=k)cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    return 0;
}