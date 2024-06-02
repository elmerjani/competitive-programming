#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        int k=n+m+1;
        ll a[k],b[k];
        for(int i=0;i<k;i++)cin>>a[i];
        for(int i=0;i<k;i++)cin>>b[i];
        
        set<int> programmers,testers;
        ll teamScore=0;
        for(int i=1;i<k;i++){
            if(a[i]>b[i]){
                if(programmers.size()==n){
                    teamScore+=b[i];
                    testers.insert(i);
                }
                else{
                    teamScore+=a[i];
                    programmers.insert(i);
                }
            }
            else {
                if(testers.size()==m){
                    teamScore+=a[i];
                    programmers.insert(i);
                }
                else{
                    teamScore+=b[i];
                    testers.insert(i);
                }
            }
        }
        cout<<teamScore<<" ";
        for(int i=0;i<k-1;i++){
            if(programmers.find(i+1)!=programmers.end()){

                programmers.erase(i+1);
                teamScore-=(a[i+1]);
            }
            else {
                testers.erase(i+1);
                teamScore-=(b[i+1]);
            }
            if(a[i]>b[i]){
                if(programmers.size()!=n){
                    teamScore+=a[i];
                    programmers.insert(i);
                }
                else if(n==0){
                    teamScore+=b[i];
                    testers.insert(i);
                }
                else{
                    auto it =programmers.rbegin();
                    if(*it>i){
                        teamScore+=a[i];
                        teamScore-=a[*it];
                        teamScore+=b[*it];
                        testers.insert(*it);
                        programmers.erase(*it);
                        programmers.insert(i);
                    }
                    else{
                        teamScore+=b[i];
                        testers.insert(i);
                    }
                    
                }
            }
            else {
                if(testers.size()!=m){
                    teamScore+=b[i];
                    testers.insert(i);
                }
                else if(m==0){
                    teamScore+=a[i];
                    programmers.insert(i);
                }
                else{
                    auto it =testers.rbegin();
                    if(*it>i){
                        teamScore+=b[i];
                        teamScore-=b[*it];
                        teamScore+=a[*it];
                        programmers.insert(*it);
                        testers.erase(*it);
                        testers.insert(i);
                    }
                    else{
                        teamScore+=a[i];
                        programmers.insert(i);
                    }
                    
                    
                }

            }
            cout<<teamScore<<" ";
        }
        cout<<"\n";

    }
}