#include <bits/stdc++.h>
using namespace std;
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
        int left=1,right=1;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                
               
                    long long f=sumArr[j]-sumArr[i-1]-(xorArr[j]^xorArr[i-1]);
                    if(f>ans){
                        ans=f;
                        left=i;
                        right=j;
                    }
                    else if(f==ans){
                        if(right-left>j-i){
                            left=i;
                            right=j;
                        }
                    }

                
            }
        }
        cout<<left<<" "<<right<<"\n";
    }
}