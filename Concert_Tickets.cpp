#include <bits/stdc++.h>
using namespace std;
int binSearch(vector<int> h,int target,unordered_map<int,int> &mp,int low,int high){
    if(low>high)return -1;
   
    else{
        int mid=low+(high-low)/2;
        if(h[mid]==target){
            if(mp[target]!=0){
                mp[target]--;
                return target;
            }
            else{
                return binSearch(h,target,mp,low,mid-1);
            }
            
        }
        else if(h[mid]>target){
            return binSearch(h,target,mp,low,mid-1);
        }
        else{
            int x=binSearch(h,target,mp,mid+1,high);
            if(x==-1){
                if(mp[h[mid]]==0)return binSearch(h,target,mp,low,mid-1);
                else{
                    mp[h[mid]]--;
                    return h[mid];
                }
            }
            else{
                return x;
            }
        }
    
    }
    return -1;
    

}
int main(){
    int n,m;cin>>n>>m;
    vector<int> h;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int ai;cin>>ai;
        if(mp.find(ai)==mp.end())h.push_back(ai);
        mp[ai]++;
        
    }
    int high=h.size();
    sort(h.begin(),h.end());
    for(int j=0;j<m;j++){
        int ti;cin>>ti;
        
        cout<<binSearch(h,ti,mp,0,high-1)<<"\n";
    }
    
}