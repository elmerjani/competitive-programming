#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i=0;i<numRows;i++){
        vector<int> temp;
        for(int j=0;j<=i;j++){
            if(j==0 || j==i)temp.push_back(1);
            else temp.push_back(ans[i-1][j]+ans[i-1][j-1]);
        }
        ans.push_back(temp);

    }
    return ans;
}

        

int main(){
    int n;
    cin>>n;
    vector<vector<int>> pascale=generate(n);
    for(int i=0;i<pascale.size();i++){
        for(int j=0;j<pascale[i].size();j++){
            cout<<pascale[i][j]<<" ";
        }
        cout<<endl;
    }

}