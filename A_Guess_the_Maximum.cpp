#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+1;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int minimum=INF;
        for(int i=0;i<n-1;i++){
            minimum=min(minimum,max(a[i],a[i+1]));
        }
        cout<<minimum-1<<endl;

    }
}