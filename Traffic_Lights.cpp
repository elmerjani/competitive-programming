#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,n;cin>>x>>n;
    set<int> s;
    multiset<int> mult;
    mult.insert(x);
    s.insert(0);
    s.insert(x);
    for(int i=0;i<n;i++){
       int pi;cin>>pi;
       s.insert(pi);
       auto it=s.find(pi);
       auto low=prev(it),high=next(it);
       auto el=mult.find(*high - *low);
       mult.erase(el);
       mult.insert(pi - *low);
       mult.insert(*high - pi);
       cout<<*mult.rbegin()<<" ";
    }
    cout<<"\n";
}