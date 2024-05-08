#include <iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
        if(n%2==0){
            for(int i=n;i>=2;i-=2)cout<<i<<" ";
        }
        else{
            for(int i=n-1;i>=2;i-=2)cout<<i<<" ";
        }
        cout<<endl;
    }

}