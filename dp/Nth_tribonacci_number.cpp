#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=1)cout<<n<<"\n";
    else{
        int t0=9,t1=1,t2=1;
        for(int i=3;i<=n;i++){
            int tmp=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=tmp;
        }
        cout<<t2<<"\n";
        return 0;
    }
}