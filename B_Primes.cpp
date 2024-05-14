#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n<=1)return false;
    for(int i=2;i<=n/i;i++){
        if(n%i==0)return false;
    }
    return true;
}
int main(){
    int n;cin>>n;
    if(n==2)cout<<-1<<endl;
    else{
        if(isprime(n-2)){
            cout<<2<<" "<<n-2<<endl;
        }
        else cout<<-1<<"\n";
    }


}