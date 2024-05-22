#include <bits/stdc++.h>
using namespace srd;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int p1,p2,p3;
        cin>>p1>>p2>>p3;
        int count=0;
        while(p1!=0){
            p1--;
            p3--;
            count++;
        }
        while(p2!=0){
            p2--;
            p3--;
            count++;
        }
        if(p3%2==0)cout<<count<<"\n";
        else cout<<-1<<"\n";
    }

}