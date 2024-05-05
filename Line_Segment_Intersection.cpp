#include <bits/stdc++.h> 
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll scal=(x2-x1)*(y4-y3)-(y2-y1)*(x4-x3);
        if(scal==0){
            ll miniscal=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
            if(miniscal==0){
                if(x2-x1==x4-x3){

                }
                else{
                    
                }

            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}