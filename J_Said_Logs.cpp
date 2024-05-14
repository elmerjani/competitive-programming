#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    int c=0,x=0;
    while(t--){
        string s;cin>>s;
        if(s=="ERROR")x++;
        else if(s=="RESOLVED" && x>0){
            c++;
            x--;
        }


    }
    cout<<c<<endl;
    return 0;
} 