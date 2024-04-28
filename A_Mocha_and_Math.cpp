#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int w;
        cin>>w;
        //int a[n]={};
        for(int  i=1;i<n;i++){
            int ai;
            cin>>ai;
            w=w&ai;
        }
        
        cout<<w<<endl;        
    }
}