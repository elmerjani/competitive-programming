#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;cin>>n;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        int ki;cin>>ki;
        s.insert({ki,i});
        auto it= s.upper_bound({ki,i});
        if(it!=s.end())s.erase(it);
    }
    cout<<(s.size())<<endl;
    return 0;
}