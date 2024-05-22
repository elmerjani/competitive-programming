#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
long sum(vector<long> prefixSum,int l,int r){
    if(r<=l)return 0;
    return prefixSum[r-1]-prefixSum[l-1];

}
pair<int,int> maxSubArraySum(vector<int> ,int start,int end)
{
    if(start>=end)return 0;
    int left=start,right=strat;
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = start; i < end; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here){
            right=i;
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0){
            left=i;
            max_ending_here = 0;
        }
    }
    return {left,right};
}

long getMaximumGrossValue(vector<int> arr) {
    int n = arr.size();
    pair<int,int> p=maxSubArraySum(arr,0,n);
    if(p.first==0){
        pair<int,int> p2=maxSubArraySum(arr,p.second+1,)
    }
}

// Example usage
int main() {
    vector<int> arr = {-5,3,9,4  };
    long result = getMaximumGrossValue(arr);
    // Expected output: 21
    cout << "Maximum Gross Value: " << result << endl;
    return 0;
}
