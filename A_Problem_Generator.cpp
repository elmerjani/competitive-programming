    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int t;cin>>t;
        while(t--){
            int n,m;cin>>n>>m;
            string s;cin>>s;
            vector<int> freq(26,0);
            for(int i=0;i<n;i++){
                freq[s[i]-'A']++;
            }
            int ans=0;
            for(int i=0;i<=6;i++){
                ans+=max(0,m-freq[i]);
            }
            cout<<ans<<endl;
        }
    }