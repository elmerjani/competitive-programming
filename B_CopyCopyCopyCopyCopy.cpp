#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        unordered_set<int> m;
        int count=n;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            if(m.count(x))count--;
            else m.insert(x);
        }
        
        cout<<count<<endl;
    }
}