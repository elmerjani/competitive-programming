#include <bits/stdc++.h>
using namespace std;
unordered_set<int> primes(int n){
    unordered_set<int> s;
    vector<bool> isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            s.insert(i);
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    
    for(int i=n;i>=n/i;i--){
        if(isPrime[i])s.insert(i);
    }
    return s;
}
int main(){
    int n;cin>>n;
    if(n<=2)cout<<1<<"\n";
    else cout<<2<<"\n";
    unordered_set<int> s=primes(n+1);
    for(int i=2;i<=n+1;i++){
        if(s.find(i)==s.end()){
            cout<<2<<" ";
        }
        else cout<<1<<" ";
    }
    cout<<"\n";
    return 0;

}