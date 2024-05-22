#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<bool> possible1(n, false), possible2(n, false);

    for (int k = 0; k <= n/2 ; ++k) {
        if (2 * k > n) break;
        
        for (int i = 0; i < k; ++i) {
            possible2[i] = true;
            possible1[i] = true;
        }
        int i1=k,i2=k;
        for(int t=0;t<n-2*k;t++){
            if(a[i1]<a[i2]){
                possible1[i1]=true;
                i1++;
            }
            else if(a[i1]>a[i2]){
                possible2[i2]=true;
                i2++;
            }

        }
        

        
    }
    for (int i = 0; i < n; ++i) {
        cout << (possible1[i] ? '1' : '0');
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << (possible2[i] ? '1' : '0');
    }
    cout << endl;

    return 0;
}
