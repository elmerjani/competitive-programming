#include <iostream>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

int main() {
    int n;
    string S1, S2;
    cin >> n >> S1 >> S2;

    int steps = 0;
    for (int i = 0; i < n; ++i) {
        int diff = S2[i] - S1[i];
        if (diff < 0) diff += 26;  // Handling circular shift
        steps += diff;
        if (steps > 26) {
            cout << -1 << endl;
            return 0;
        }
    }

    int result = factorial(steps);
    cout << result << endl;

    return 0;
}
