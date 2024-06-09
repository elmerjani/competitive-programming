#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll c=0;
        for(int i=0;i<n;i++){
            if(a[i]>=0)c+=a[i];
            else{
                if(c+a[i]>=0){
                    c+=a[i];
                }
                else{
                    int j=i+1;
                    ll pos=0;
                    while(j<n && a[j]>=0){
                        pos+=a[j];
                        j++;
                    }
                    if(j==n){
                        c=pos+abs(c+a[i]);
                        break;
                    }
                    else{
                        if(c+a[i]+pos<=0){
                            c=c+a[i]+pos;
                        }
                        else{
                            c=abs(c+a[i])+pos;
                        }
                    }
                    i=j-1;

                }
                
            }
        }
        cout<<c<<endl;

    }
}