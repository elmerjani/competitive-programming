#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+1;
vector<int> position(MAXN);
vector<bool> correct(MAXN,false);
vector<int> a(MAXN);
void tt(vector<int> position,int x,int n,int &count){
    if(x==1){
        if(position[1]<position[2]&&!correct[1]){
            count--;
            correct[1]=true;
        }
        else if(position[1]>position[2]&&correct[1]){
            correct[1]=false;
            count++;
        }
    }
    else if(x==n){
        if(position[n-1]<position[n]&&!correct[n-1]){
            correct[n-1]=true;
            count--;
        }
        else if(position[n-1]>position[n]&& correct[n-1]){
            correct[n-1]=false;
            count++;
        }

    }
    else{
        if(position[x-1]<position[x]&&!correct[x-1]){
            correct[x-1]=true;
            count--;
        }
        else if(position[x-1]>position[x]&&correct[x-1]){
            correct[x-1]=false;
            count++;
        }
        if(position[x]<position[x+1]&&!correct[x]){
            correct[x]=true;
            count--;
        }
        else if(position[x]>position[x+1]&&correct[x]){
            correct[x]=false;
            count++;
        }

    }
}
void swap(vector<int> &a,int l,int r){
    int tmp=a[l];
    a[l]=a[r];
    a[r]=tmp;
}
int main(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        int ai;cin>>ai;
        a[i]=ai;
        position[ai]=i;
    }
    int count=n;
    for(int i=1;i<n;i++){
        if(position[i]<position[i+1]){
            
            correct[i]=true;
            count--;
        }
    }
    while(q--){
        int l,r;cin>>l>>r;
        position[a[l]]=r;
        position[a[r]]=l;
        swap(a,l,r);
        tt(position,a[l],n,count);
        tt(position,a[r],n,count);
        cout<<count<<endl;
    }
    
    

}