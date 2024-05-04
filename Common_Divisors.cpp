#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    int maxDiv=1;
    unordered_set<int> s;
    while(n--){
        int x;cin>>x;
        if(s.count(x)){
            maxDiv=max(maxDiv,x);
            continue;
        }
        int sq=sqrt(x);
        for(int i=1;i<=sq;i++ ){
            if(x%i==0){
                if(s.count(x/i)){
                    maxDiv=max(maxDiv,x/i);
                }
                else{
                    if(s.count(i)){
                        maxDiv=max(maxDiv,i);
                    }
                }
                s.insert(i);
                s.insert(x/i);
            }
        }
        
    }
    cout<<maxDiv<<endl;
}