#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n,0);
        int x[n-1];
        for(int i=0;i<n-1;i++){
            cin>>x[i];
        }
        a[0]=x[0]+1;
        for(int i=1;i<n-1;i++){
            int k=0;
            while(k*a[i-1]+x[i-1]<=x[i])k++;
            a[i]=k*a[i-1]+x[i-1];
        }
        a[n-1]=x[n-2];
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
}