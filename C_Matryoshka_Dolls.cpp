#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,x;cin>>s>>x;
    int count=1;
    while(s>=x){
        count++;
        s/=x;
    }
    cout<<count<<endl;
    return 0;
}