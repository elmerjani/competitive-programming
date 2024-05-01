#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='U')count++;
        }
        cout<<(count%2==0?"NO":"YES")<<"\n";
    }
}