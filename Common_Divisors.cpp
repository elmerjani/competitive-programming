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
        int ai;
        cin>>ai;
        freq[ai]++;
    }
    int maxgcd=1;
    for(int i=MAXN-1;i>=2;i--){
        int count=0;
        for(int j=i;j<MAXN;j+=i){
            count+=freq[j];
            if(count>=2)break;    
        }
        if(count>=2){
            maxgcd=i;
            break;
        }
        
    }
    cout<<maxgcd<<"\n";
    return 0;
    

    
}