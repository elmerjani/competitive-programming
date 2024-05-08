#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        
        long long sum=0;
        long long sumArr[n+1]={};
        sumArr[0]=0;
        long long cor=0;
        long long xorArr[n+1]={};
        xorArr[0]=0;
        for(int i=1;i<=n;i++){
            long long ai;
            cin>>ai;
            
            sum+=ai;
            sumArr[i]=sum;
            cor^=ai;
            xorArr[i]=cor;
        }
        int a,b;cin>>a>>b;
        long long ans=0;
        int left=1,right=n;
        for(int i=1;i<=n;i++){
            ll f=sumArr[n]-sumArr[i-1]-xorArr[n]^xorArr[i-1];
            if(f<ans)continue;
            else {
                //ans=f;
                int l=i,r=n;
                while(l<r){
                    int mid=l+(r-l)/2;
                    if(sumArr[mid]-sumArr[i-1]-xorArr[mid]^xorArr[i-1]<f)l=mid+1;
                    else r=mid;
                }
                if(f==ans){
                    if(r-i<right-left){
                        left=i;
                        right=l;
                    }
                }
                else{
                    ans=f;
                    left=i;
                    right=l;    

                }
            }
        }
        cout<<left<<" "<<right<<"\n";
    }
}