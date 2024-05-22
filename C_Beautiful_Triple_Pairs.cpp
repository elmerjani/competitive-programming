    #include <bits/stdc++.h>
   using namespace std;
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t;cin>>t;
        while(t--){
            int n;cin>>n;
            vector<int> a(n);
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            long long  counter=0;
            for(int i=0;i<n-3;i++){
                for(int j=i+1;j<n-2;j++){
                    if(((a[i]==a[j]&& a[i+1]==a[j+1]&&a[i+2]!=a[j+2])||
                        (a[i]==a[j]&& a[i+1]!=a[j+1]&& a[i+2]==a[j+2])||
                        (a[i]!=a[j]&& a[i+1]==a[j+1]&&a[i+2]==a[j+2]))){
                        counter ++;
                    }
                }
                
            }
            cout<<counter<<endl;
            
        }
        
        
    }