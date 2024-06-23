    #include <bits/stdc++.h>
    using namespace std;
    bool sorted(vector<int> a){
        int n=a.size();
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1])return false;
        }
        return true;
    }
    vector<int> split(int i,vector<int> a,int n){
        vector<int> ans;
        for(int j=i;j<n;j++){
            ans.push_back(a[j]);
        }
        for(int j=0;j<i;j++){
            ans.push_back(a[j]);
        }
        return ans;
    }
    int main(){
        int t;cin>>t;
        while(t--){
            int n;cin>>n;
            vector<int>  a(n);
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            bool can=false;
            for(int i=0;i<n;i++){
                vector<int> ans=split(i,a,n);
                if(sorted(ans)){
                    cout<<"YES\n";
                    can=true;
                    break;
                }
            }
            if(!can)cout<<"NO\n";
        }
            
    }