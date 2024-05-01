#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;   
        int a[n],b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(b[i]<a[j]){
                ans++;
            }
            else j++;

        }
        cout<<ans<<endl;
    }
}