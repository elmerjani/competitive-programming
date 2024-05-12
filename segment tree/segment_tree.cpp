#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tree;
void update(ll ans,int k){
    while(k>0){
        tree[k]+=ans;
        k/=2;
    }


}
ll query(int node,int left,int right,int low,int high){
    if(left>=low && right<=high)return tree[node];
    if(right<low || left>high)return 0;
    int next=(left+right)/2;
    return query(2*node,left,next,low,high)+query(2*node+1,next+1,right,low,high);

}
int main(){
    int n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    while(__builtin_popcount(n)!=1){
        n++;
        a.push_back(0);
    }
    tree.resize(2*n);
    for(int i=n;i<2*n;i++){
        tree[i]=a[i-n];
    }
    for(int i=n-1;i>0;i--){
        tree[i]=tree[2*i]+tree[2*i+1];
    }
    while(q--){
        int type;cin>>type;
        if(type==1){
            int k ;ll u;
            cin>>k>>u;
            ll ans=u-a[k-1];
            
            update(ans,k+n-1);
            a[k-1]=u;
            

        }
        else{
            int low,high;
            cin>>low>>high;
            low--;high--;
            cout<<query(1,0,n-1,low,high)<<"\n";

        }
        
    }
}