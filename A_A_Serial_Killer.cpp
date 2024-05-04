#include <bits/stdc++.h>
using namespace std;
int main(){
    string firsttarget,secondtarget;
    cin>>firsttarget>>secondtarget;
    int n;cin>>n;
    for(int i=0;i<=n;i++){
        cout<<firsttarget<<" "<<secondtarget<<"\n";
        string murdered,replace;
        cin>>murdered>>replace;
        if(murdered==firsttarget){
            firsttarget=replace;
        }
        else{
            secondtarget=replace;
        }
    }
}