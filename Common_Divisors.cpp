#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
vector<int> freq(MAXN,0);
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int ai;cin>>ai;
        freq[ai]++;
    }
    //for(int i=0;i<100;i++)cout<<freq[i]<<" ";
    
    for(int i=MAXN;i>0;i--){
        if(freq[i]>1){
            cout<<i<<"\n";
            return 0;  
        }
        else if(freq[i]){
            for(int j=i;j<=MAXN;j+=i){
                if(j==i)continue;
                if(freq[j]){
                    cout<<i<<"\n";
                    return 0;
                }
            }
        }
    }

    
}