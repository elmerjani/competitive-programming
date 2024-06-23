#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(int n){
    return ((int)sqrt(n))*((int)sqrt(n))==n;
}
bool isSumSquare(int n){
    for(int i=0;i*i<=n;i++){
        if(isPerfectSquare(n-i*i)){
            cout<<i*i<<" "<<n-i*i<<"\n";
            return true;
        }
    }
    return false;
}
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" "<<n/i<<"\n";
            return false;
        }
    }
    return true;
}
int main(){
    int n;cin>>n;
    if(isPrime(n))cout<<"YES\n";
    else cout<<"NO\n";

}