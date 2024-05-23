#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        ll s;cin>>s;
        ll ans=0;
        while(s>=10){
            ans+=s-s%10;
            ll tmp=(s-s%10)/10;
            s-=(s-s%10);
            s+=tmp;
        }
        ans+=s;
        cout<<ans<<endl;
    }
}
