#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        int p1,p2,p3;
        cin>>p1>>p2>>p3;
        
        if((p1+p2+p3)%2==1){
            cout<<-1<<"\n";
            continue;
        }
        int p[]={p1,p2,p3};
        int count=0;
        while(p[1]!=0){
            count++;
            p[2]--;
            p[1]--;
            sort(p,p+3);

        }
        cout<<count<<"\n";
        
    }

}