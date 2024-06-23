#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m,x;
        cin>>n>>m>>x;
        unordered_set<int> q;
        q.insert(x);
        for(int i=0;i<m;i++){
            int len;cin>>len;
            char direction;cin>>direction;
            unordered_set<int> aux;
            for(auto p:q){
                if(direction=='0'|| direction=='?')aux.insert((p+len-1)%n+1);
                if(direction=='1'||direction=='?')aux.insert((p-len-1+n)%n+1);
            }
            q=aux;

        }
        cout<<q.size()<<endl;
        vector<int> ans;
        for(int p:q)ans.push_back(p);
        sort(ans.begin(),ans.end());
        for(auto p:ans)cout<<p<<" ";
        cout<<endl;

    }
}