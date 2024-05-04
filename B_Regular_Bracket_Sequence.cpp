#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.size();
    int brackets=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            brackets++;
            
        }
        else if(s[i]==')'){
            if(brackets!=0){
                count+=2;
                brackets--;
            }
        }
    }
    cout<<count<<"\n";
}