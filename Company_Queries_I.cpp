#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;cin>>n>>q;
    int log[n+1];
    log[1]=0;
    for(int i=2;i<=n;i++){
        log[i]=log[i/2]+1;
    }
    vector<int> bosses(n+1,-1);
    vector<vector<int>> m(n+1,vector<int>(log[n]+1,-1));
    for(int i=2;i<=n;i++){
        cin>>bosses[i];
        m[i][0]=bosses[i];
    }
    
    
    
    for(int k=1;k<=log[n];k++){
        for(int i=2;i<=n;i++){
            if(m[i][k-1]!=-1)m[i][k]=m[m[i][k-1]][k-1];
        }
    }
    
    while(q--){
        int x,k;cin>>x>>k;
        int ans=0;
        while(k!=0){
            if(x==-1)break;
            if(k%2){
                x=m[x][ans];
            }
            k/=2;
            ans++;

        }
        cout<<x<<"\n";

    }

}
//m[i][k]2^kth boss of i
//5=101