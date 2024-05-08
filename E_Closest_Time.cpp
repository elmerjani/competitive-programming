#include <bits/stdc++.h>
using namespace std;
bool match(int hours,int minuts,string given){
    int a[]={hours/10,hours%10,minuts/10,minuts%10};
    char c[]={given[0],given[1],given[3],given[4]};
    for(int i=0;i<4;i++){
        if(c[i]!='?'&&c[i]-'0'!=a[i]){
            return false;
        }
    }
    return true;
}
int parse(string given){
    char c[]={given[0]-'0',given[1]-'0',given[3]-'0',given[4]-'0'};
    return 60*(c[0]*10+c[1]*1)+c[2]*10+c[3]*1;
}
void deparse(int hour,int minut){
    cout<<hour/10<<hour%10<<":"<<minut/10<<minut%10<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        string given,ref;
        int ans=2000;
        cin>>given>>ref;
        int hour=0,minut=0;
        for(int i=0;i<24;i++){
            for(int j=0;j<60;j++){
                if(match(i,j,given)){ 
                    if(60*i+j>parse(ref)){
                        if((60*i+j-parse(ref))<ans || (24-i)*60-j+parse(ref)<ans){
                            ans=min((60*i+j-parse(ref)), (24-i)*60-j+parse(ref));
                            hour=i;minut=j;
                        }
                    }
                    else{
                        if(-(60*i+j-parse(ref))<ans || i*60+j+60*(24-(10*(ref[0]-'0')+(ref[1]-'0')))-(10*(ref[3]-'0')+(ref[4]-'0'))<ans){
                            ans=min(-(60*i+j-parse(ref)), i*60+j+60*(24-(10*(ref[0]-'0')+(ref[1]-'0')))-(10*(ref[3]-'0')+(ref[4]-'0')));
                            hour=i;minut=j;
                        }

                    }
                }
            }
        }
        deparse(hour,minut);
    }
}