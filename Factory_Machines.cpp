#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canProduce(const vector<int>& machines, int t, long long time) {
    long long totalProducts = 0;
    for (int machine : machines) {
        totalProducts += time / machine;
        // Optimization: if already exceeds t, return true
        if (totalProducts >= t)
            return true;
    }
    return totalProducts >= t;
}

int main() {
    int n, t;
    cin >> n >> t;
    
    vector<int> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }
    
    long long left = 0;
    long long right = *max_element(machines.begin(), machines.end()) * static_cast<long long>(t);
    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (canProduce(machines, t, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;

    return 0;
}
