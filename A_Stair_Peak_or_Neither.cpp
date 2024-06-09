#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int m=2*n;
        int k=0,p=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if((i%4==0 || i%4==1)&&(i%4==0 || i%4==1))cout<<"#";
                else cout<<".";
            }
            cout<<"\n";
        }
        
    }
}