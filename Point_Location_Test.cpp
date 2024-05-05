#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        ll x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        ll a=x3-x1,b=y2-y1,c=x2-x1,d=y3-y1;
        ll ans=a*b-c*d;
        //cout<<ans<<"\n";
        if(ans==0)cout<<"TOUCH"<<"\n";
        else if(ans>0)cout<<"RIGHT"<<"\n";
        else cout<<"LEFT"<<"\n";
    }
}