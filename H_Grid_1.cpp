#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
long sum(vector<long> prefixSum,int l,int r){
    if(r<=l)return 0;
    return prefixSum[r-1]-prefixSum[l-1];

}

long getMaximumGrossValue(vector<int> arr) {
    int n = arr.size();
    
    // Step 1: Compute the prefix sum array
    vector<long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    
    long max_gross_value = LONG_MIN;
    
    // Step 2: Iterate over all possible triplets
    for (int i1 = 1; i1 <= n+1; ++i1) {
        for (int i2 = i1 ; i2 <= n+1; ++i2) {
            for (int i3 = i2 ; i3 <= n+1; ++i3) {
                long sum1 = sum(prefix,1,i1);
                long sum2 = sum(prefix,i1,i2);
                long sum3 = sum(prefix,i2,i3);
                long sum4 = sum(prefix,i3,n+1);
                long gross_value = sum1 - sum2 + sum3 - sum4;
                max_gross_value = max(max_gross_value, gross_value);
            }
        }
    }
    
    return max_gross_value;
}

// Example usage
int main() {
    vector<int> arr = {4, -8, 2, -10,3,-20  };
    long result = getMaximumGrossValue(arr);
    // Expected output: 21
    cout << "Maximum Gross Value: " << result << endl;
    return 0;
}
