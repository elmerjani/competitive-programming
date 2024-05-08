#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        stack<int> st;
        int count=0;
        for(int i=0;i<n;i++){
            int ai;cin>>ai;
            if(s[i]=='0')st.push(ai);
            else{
                if(st.empty()){
                    count+=ai;
                }
                else{
                    if(st.top()>ai){
                        count+=st.top();
                        st.pop();
                        st.push(ai);
                    }
                    else{
                        count+=ai;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
}