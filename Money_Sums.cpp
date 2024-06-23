#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
int main(){
    int n;cin>>n;
    int coins[n];
    for(int i=0;i<n;i++)cin>>coins[i];
    vector<bool> possible(MAXN,false);
    possible[0]=true;
    for(int i=0;i<n;i++){
        for(int j=MAXN;j>=0;j--){
            if(possible[j] && j+coins[i]<=MAXN)possible[j+coins[i]]=true;
        }        
    }
    int count=0;
    for(int i=1;i<=MAXN;i++){
        if(possible[i])count++;
    }
    cout<<count<<endl;
    for(int i=1;i<=MAXN;i++){
        if(possible[i])cout<<i<<" ";
    }
    cout<<endl;
    return 0;

}