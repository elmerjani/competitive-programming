#include <bits/stdc++.h>
using namespace std;
int MAXN=1000000001;

vector<int> tree;
void update(int u,int k){
    while(k>1){
        if(k%2==0){
            tree[k/2]=min(tree[k],tree[k+1]);

        }
        else{
            tree[k/2]=min(tree[k],tree[k-1]);

        }
        k/=2;
    }


}
int query(int node,int left,int right,int low,int high){
    if(left>=low && right<=high)return tree[node];
    if(right<low || left>high)return MAXN;
    int next=(left+right)/2;
    return min(query(2*node,left,next,low,high),query(2*node+1,next+1,right,low,high));

}
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    while(__builtin_popcount(n)!=1){
        n++;
        a.push_back(MAXN);
    }
    tree.resize(2*n);
    for(int i=n;i<2*n;i++){
        tree[i]=a[i-n];
    }
    for(int i=n-1;i>0;i--){
        tree[i]=min(tree[2*i],tree[2*i+1]);
    }
    while(q--){
        int type;cin>>type;
        if(type==1){
            int k ;int u;
            cin>>k>>u;
            k--;
            tree[k+n]=u;
            update(u,k+n);
            
            

        }
        else{
            int low,high;
            cin>>low>>high;
            low--;high--;
            cout<<query(1,0,n-1,low,high)<<"\n";

        }
        
    }
}