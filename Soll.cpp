#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> max_magnitude(int t, vector<pair<int, vector<long long>>>& test_cases) {
    vector<long long> results;
    for (int i = 0; i < t; ++i) {
        int n = test_cases[i].first;
        vector<long long>& a = test_cases[i].second;
        long long c = 0;
        for (int j = 0; j < n; ++j) {
            c += a[j];
            if (c < 0) {
                c = abs(c);
            }
        }
        results.push_back(c);
    }
    return results;
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, vector<long long>>> test_cases(t);
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        test_cases[i] = {n, a};
    }
    
    vector<long long> results = max_magnitude(t, test_cases);
    for (long long result : results) {
        cout << result << endl;
    }
    
    return 0;
}
