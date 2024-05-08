#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1e9+7;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        int i=n-1,j=n-1;
        int count=0;
        int aux[n]={};
        while(i>=0 &&j>=0){
            if(a[i]>b[j]){
                count++;
                i--;
            }
            else{
                aux[j]=count;
                j--;
            }
        }
        while(j>=0){
            aux[j]=count;
            j--;
        }
        ll ans=1;
        for(int i=0;i<n;i++){
            ans*=(aux[n-i-1]-i);
            ans%=MOD;
        }
        cout<<ans<<"\n";
    }
}