#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
int main(){
    vector<bool> binary(MAXN+1,false);
    binary[1]=binary[10]=binary[11]=true;
    vector<int> bin={10,11};
    int i=0;
    while(i<bin.size()){
        for(int j=i;j<bin.size();j++){
            if(bin[i]*bin[j]>MAXN)break;
            binary[bin[i]*bin[j]]=true;
            bin.push_back(bin[i]*bin[j]);
        }
        i++;
    }
    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(binary[n])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        
    }

}