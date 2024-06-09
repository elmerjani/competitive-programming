#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bfs(int start,const vector<int> adj[],vector<bool> used,const vector<int> nums){
        used[start]=true;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int u=q.front();
            if(nums[u]==0)return true;
            q.pop();
            for(auto v:adj[u]){
                if(!used[v]){
                    used[v]=true;
                    q.push(v);
                }
            }
        }
        return false;

    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> adj[n];
        vector<bool> used(n,false);
        for(int i=0;i<n;i++){
            if(i+arr[i]<n){
                adj[i].push_back(i+arr[i]);
                adj[i+arr[i]].push_back(i);
            }
            if(i-arr[i]>=0){
                adj[i].push_back(i-arr[i]);
                adj[i-arr[i]].push_back(i);
            }
        }
        return bfs(start,adj,used,arr);
        
        
    }
};
int main(){
    vector<int> arr={3,0,2,1,2};
    int start=2;
    Solution s;
    if(s.canReach(arr,start))cout<<"true\n";
    else cout<<"false\n";
    

}