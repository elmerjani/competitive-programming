#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    while(n--){
        int x;cin>>x;
        int sq=sqrt(x);
        int counter=0;
        for(int i=1;i<=sq;i++){
            if(x%i==0)counter+=2;
        }
        if(sq*sq==x)counter--;
        cout<<counter<<"\n";
        
            
        
        
    }

}