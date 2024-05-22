#include <bits/stdc++.h>
using namespace std;
int  main(){
    int t;cin>>t;
    while(t--){
        vector<int> freq(26,0);
        int n;cin>>n;
        string s;cin>>s;
        string dist="";
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        unordered_map<char,int> mp;
        int j=0;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                mp[i+'a']=j++;
                dist+=char(i+'a');
            }
        }
        int x=dist.size();
        for(int i=0;i<n;i++){
            cout<<dist[x-mp[s[i]]-1];

        }
        //cout<<dist;
        cout<<"\n";
    }
}