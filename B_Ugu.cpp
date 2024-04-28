#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int count=0;
        int i=0;
        while(i<n&&s[i]=='0'){
            i++;
        }
        i++;
        int countrev=0;
        bool rev=false;
        for(i;i<n;i++){
            if((s[i]=='1' && (countrev%2==1))||(s[i]=='0'&&(countrev%2==0))){
                count++;
                countrev++;
            }
        }
        cout<<count<<endl;
    

    }
}