#include <bits/stdc++.h>
using namespace std;
long long binSearch(long long k,long long sum[],long long a[],long long n){
    long long low=0,high=n-1;
    while(low<=high){
        long long  mid=low+(high-low)/2;
        if(mid==0){
            if(k<(mid+1)*a[mid+1]-sum[mid])return mid;
            
            return mid+1;
        }
        if(mid==n-1){
            if(k>=mid*a[mid]-sum[mid-1]){
                
                return mid;
            }
            
            return mid-1;
        }
        
        if( (k>=mid*a[mid]-sum[mid-1] &&k<(mid+1)*a[mid+1]-sum[mid])){
            
            return mid;
        }
        if(k<mid*a[mid]-sum[mid-1])high=mid-1;
        else low=mid+1;

    }
    return low;
}
int main(){
    int t;cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        if(n==1){
            long long a0;cin>>a0;
            cout<<a0+k<<'\n';
            
        }
        else{
            long long sum[n];
            long long s=0;
            long long a[n],b[n];
            for(int i=0;i<n;i++){
                cin>>a[i];
                b[i]=a[i];
                
                sum[i]=s;
            }
            sort(a,a+n);
            for(int i=0;i<n;i++){
                s+=a[i];
                sum[i]=s;
            }
            long long ans=binSearch(k,sum,a,n);
            if(ans==0){
                a[0]+=k;
                k=0;
            }
            if(ans!=0)k=k-(ans*a[ans]-sum[ans-1]);

            
            long long numans=(a[ans]-1)*n+1;
            long long interright=0,interleft=0;
            long long kright=k,kleft=k;
            int i=0;
        while(i<n){
            if(b[i]>a[ans]){
                interright++;
            }
            else{
                if(kright==0)break;
                kright--;
                interright++;
            }
            i++;
        }
        i=n-1;
        while(i>=0){
            if(b[i]>a[ans])interleft++;
            else{
                if(kleft==0)break;
                kleft--;
                interleft++;
            }
            i--;
        }
        numans+=(max(interleft,interright));
            
            //for(int i=0;i<n;i++)cout<<sum[i]<<" ";
            cout<<numans<<"\n";
            
        } 
       
        
    }
}
/*int i=0;
        while(i<n){
            if(b[i]>a[ans]){
                numans++;
            }
            else{
                if(k==0)break;
                k--;
                numans++;
            }
        }
        cout<<numans<<'\n';*/