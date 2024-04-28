#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int gcdAll(vector<int>  &a){
    int gcdi=a[0];
    for(int i=1;i<a.size();i++){
        gcdi=gcd(gcdi,a[i]);
    }
    return gcdi;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> cont(n);
        for(int i=0;i<n;i++){
            int ai;cin>>ai;
            cont[i]=ai;
        }
    
        int g=gcdAll(cont);
        if(g==1)cout<<0;
        else if(gcd(g,n)==1)cout<<1;
        else if(gcd(g,n-1)==1)cout<<2;
        else cout<<3;
        cout<<"\n";
    }
    
    return 0;

}