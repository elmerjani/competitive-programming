#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    
    set<pair<int,int>> tickets;
    for (int i=0;i<n;i++){
        int hi;cin>>hi;
        tickets.insert({hi,i});
    }
    int i=0;
    for (i;i<m;i++){
        int ti;
        cin>>ti;
        if(tickets.size()==0){
            cout<<-1<<endl;
            
            
        }
        else{
            auto it=tickets.lower_bound({ti+1,0});
            if(it==tickets.begin()){
                cout<<-1<<endl;
                
            }
            else{
                it--;
                cout<<(*it).first<<endl;
                tickets.erase(it);
            }
        }

    }
    
    
    
}