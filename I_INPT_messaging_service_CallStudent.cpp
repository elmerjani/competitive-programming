#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<string> st;
    unordered_map<string,int> maxval;
    int n;cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(st.find(s)!=st.end()){

            maxval[s]++;
            cout<<s<<maxval[s]<<"\n";
        }
        else{
            cout<<"OK"<<"\n";
            st.insert(s);
            //maxval[s]=1;
        }
    }

}