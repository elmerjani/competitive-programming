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
    vector<long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    int n = arr.size();
    pair<int,int> p=maxSubArraySum(arr,0,n);
    if(p.first==0){
        pair<int,int> p2=maxSubArraySum(arr,p.second+1,n);
        long sum=0;
        for(int i=p.first;i<=p.second,i++)sum+=arr[i];
        for(int i=p.second+1;i<p2.second;i++)sum+=(-arr[i]);
        for(int i=p2.first;i<=p2.second;i++)sum+=arr[i];
        for(int i=p2.second;i<n;i++)sum+=arr[i];
        return sum;

    }
    else {
        for(int)


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
