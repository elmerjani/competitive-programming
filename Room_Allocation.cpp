#include <bits/stdc++.h>
using namespace std;
int main(){
    int maxRoom=0;
    int n;cin>>n;
    vector<vector<int>> customers(n);
    for(int i=0;i<n;i++){
        int arrival,depat;
        cin>>arrival>>depat;
        customers[i]={arrival,depat,i};
    }
    //vector<pair<int,int>> inp=customers;
    sort(customers.begin(),customers.end());
    vector<int> rooms(n);
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
        int arrival=customers[i][0],depat=customers[i][1];
        auto it=s.lower_bound({arrival,0});
        if(it==s.begin()){
            maxRoom++;
            rooms[customers[i][2]]=maxRoom;
            s.insert({depat,maxRoom});
        }
        else{
            it--;
            rooms[customers[i][2]]=((*it).second);
            s.insert({depat,(*it).second});
            s.erase(it);

        }
        

    }
    cout<<maxRoom<<endl;
    for(int i=0;i<n;i++){
        cout<<rooms[i]<<" ";
    }
    cout<<"\n";
}