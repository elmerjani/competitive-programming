#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int hour=((s[0]-'0')*10+(s[1]-'0'));
        if(hour==0){
            cout<<"12:"<<s[3]<<s[4]<<" AM";
        }
        else if(hour<=12){
            if(hour<10)cout<<"0"<<hour<<":"<<s[3]<<s[4]<<" AM";
            else cout<<hour<<":"<<s[3]<<s[4]<<" AM";
        }
        else{
            hour-=12;
            if(hour<10)cout<<"0"<<hour<<":"<<s[3]<<s[4]<<" PM";
            else cout<<hour<<":"<<s[3]<<s[4]<<" PM";

        }
        
        
    }
}