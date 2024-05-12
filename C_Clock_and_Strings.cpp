#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int m=min(min(a,b),min(c,d));
        bool red=true;
        bool found=false;
        if(m==c || m==d)red=false;
        for(int i=m+1;i<=12;i++){
            if(((i==a || i==b)&& red )||((i==c||i==d)&&!red)){
                found=true;
                cout<<"NO"<<endl;
                break;
                
            }
            if((i==a || i==b))red=true;
            else if((i==c || i==d))red=false;
        }
        if(!found){
            for(int i=1;i<=m;i++){
                if(((i==a || i==b)&& red )||((i==c||i==d)&&!red)){
                    found=true;
                    cout<<"NO"<<endl;
                    break;
                    
                }
                if((i==a || i==b))red=true;
                else if((i==c || i==d))red=false;
            }
            if(!found)cout<<"YES"<<endl;
        }
    }
}