#include <bits/stdc++.h>
using namespace std;
int mex(set<int> const& b) {
     

    int result = 1;
    while (b.count(result))
        ++result;
    return result;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        int max=0;
        set<int> a;
        for(int i=0;i<n;i++){
            int ai;
            cin>>ai;
            a.insert(ai);
            if(ai>max)max=ai;
        }
        int m=mex(a);
        if(m>max){
            if(a.size()%2==0)cout<<"Bob";
            else cout<<"Alice";
        }
        else{
            if(m%2==0)cout<<"Bob";
            else cout<<"Alice";
        }
        
        cout<<"\n"; 
        
    }

    
    
    return 0;
}