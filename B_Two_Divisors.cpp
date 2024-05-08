#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int t;cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        if(b%a==0){
            cout<<b*b/a;
        }
        else {
            cout<<(a*b)/gcd(a,b);
        }
        cout<<"\n";
    }

}