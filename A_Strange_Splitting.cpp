#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+1;

int main(){
    int t;cin>>t;
    while(t--){
        int  dist=1;
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i>0 &&a[i]!=a[i-1])dist++;
            
        }
        if(dist==1){
            cout<<"NO"<<endl;
            
        }
        else if(dist==2){
            cout<<"YES"<<endl;
            if(a[0]==a[1]){
                cout<<"R";
                for(int i=1;i<n;i++){
                    cout<<"B";
                }
                cout<<endl;
            }
            else{
                cout<<"RR";
                for(int i=2;i<n;i++){
                    cout<<"B";
                }
                cout<<endl;
            }
            
        }
        else{
            cout<<"YES"<<endl;
            cout<<"R";
            for(int i=1;i<n;i++){
                cout<<"B";
            }
            cout<<endl;
        }
        
    }
}