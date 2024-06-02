#include <bits/stdc++.h>
using namespace std;
bool isDigit(char c){
    return (c>='0'&&c<='9');
}
bool isLower(char c){
    return (c>='a'&&c<='z');
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        bool valid=true;
        vector<char> chars;
        vector<char> digits;
        for(int i=0;i<n;i++){
            if(isDigit(s[i])&&(i>=0 &&isLower(s[i-1]))){
                valid=false;
                break;
            }
            if(isDigit(s[i]))digits.push_back(s[i]);
            else chars.push_back(s[i]);
        }
        for(int i=1;i<chars.size();i++){
            if(chars[i]<chars[i-1]){
                valid=false;
                break;
            }
        }
        for(int i=1;i<digits.size();i++){
            if(digits[i]<digits[i-1]){
                valid=false;
                break;
            }
        }
        if(valid )cout<<"YES\n";
        else cout<<"NO\n";

    }
}