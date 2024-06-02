#include <bits/stdc++.h>
using namespace std;
    string multiply(const string& num1, const string& num2) {
        int m = num1.length(), n = num2.length();
        vector<int> pos(m + n, 0);

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + pos[p2];

                pos[p1] += sum / 10;
                pos[p2] = sum % 10;
            }
        }

        string result;
        for(int p : pos) {
            if(!(result.empty() && p == 0)) {
                result.push_back(p + '0');
            }
        }
        return result.empty() ? "0" : result;
    }


int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string ans="1";
        for(int i=2;i<=n;i++){
            ans=multiply(ans,to_string(i));
        }
        cout<<ans<<endl;
    }
   
    
}
