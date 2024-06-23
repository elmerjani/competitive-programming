#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int maxm=0;
        int an=0;
        for(int i=0;i<n;i++){
            int ai;cin>>ai;
            if(i==n-1){
                an=ai;
            }
            else{
                maxm=max(maxm,ai);
            }
        }
        cout<<maxm+an<<"\n";
        
    }
}