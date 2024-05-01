/*#include <bits/stdc++.h>
using namespace std ;
typedef long long  ll;
pair<int,int> binSearch(vector<pair<ll,pair<int,int>>> pairs,ll target,int left,int right){
    if(left>right)return make_pair(-1,-1);
    int mid=(left+right)/2;
    if(pairs[mid].first==target)return pairs[mid].second;
    else if(pairs[mid].first<target)return binSearch(pairs,target,mid+1,right);
    else return binSearch(pairs,target,left,mid-1);

}
int main(){
    ll n,x;cin>>n>>x;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<pair<ll,pair<int,int>>> pairs;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pairs.push_back(make_pair(a[i]+a[j],make_pair(i+1,j+1)));
        }
    }
    
    int m=pairs.size();
    bool exist =false;
    sort(pairs.begin(),pairs.end());
    for(int i=0;i<m;i++){
        pair<int,int> ans=binSearch(pairs,x-pairs[i].first,i+1,m-1);
        if(ans.first==-1)continue;
        else{
            if(!(ans.first==pairs[i].second.first||ans.first==pairs[i].second.second||
            ans.second==pairs[i].second.first || ans.second==pairs[i].second.second)){
                cout<<pairs[i].second.first<<" "<<pairs[i].second.second<<" "<<ans.first<<" "<<ans.second<<endl;
                exist=true;
                break;
            }
        }
    }
    if(!exist)cout<<"IMPOSSIBLE"<<endl;

   
}*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findFourValues(int n, int x, const vector<int>& arr) {
    // Create a map to store the sum of pairs and their indices
    unordered_map<int, pair<int, int>> pairSumIndices;
    
    // Find all pairs and store their sum and indices
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int pairSum = arr[i] + arr[j];
            if (pairSumIndices.find(pairSum) == pairSumIndices.end()) {
                pairSumIndices[pairSum] = {i, j};
            }
        }
    }
    
    // Iterate through the array to find the remaining two values
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int remainingSum = x - (arr[i] + arr[j]);
            if (pairSumIndices.find(remainingSum) != pairSumIndices.end()) {
                // Ensure the indices are distinct
                auto indices = pairSumIndices[remainingSum];
                if (i != indices.first && i != indices.second && j != indices.first && j != indices.second) {
                    return {i + 1, j + 1, indices.first + 1, indices.second + 1};
                }
            }
        }
    }
    
    return {};
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = findFourValues(n, x, arr);
    if (result.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < 4; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
