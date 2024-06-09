#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int length[n];
    for(int i=0;i<n;i++){
        length[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                length[i]=max(length[i],length[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,length[i]);
    }
    cout<<ans<<endl;
    return 0;

}