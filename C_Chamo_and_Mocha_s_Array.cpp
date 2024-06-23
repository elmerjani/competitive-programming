#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==2){
            cout<<min(a[0],a[1])<<"\n";
            continue;
        }
        int maximum=0;
        for(int i=0;i+2<n;i++){
            vector<int> v={a[i],a[i+1],a[i+2]};
            sort(v.begin(),v.end());
            maximum=max(maximum,v[1]);
        }
        cout<<maximum<<"\n";


    }
}