#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

long long count_divisible(long long n, vector<long long>& primes) {
    long long count = 0;
    for (int i = 1; i < (1 << primes.size()); ++i) {
        long long lcm_val = 1;
        int bits = 0;
        for (int j = 0; j < primes.size(); ++j) {
            if (i & (1 << j)) {
                lcm_val = lcm(lcm_val, primes[j]);
                bits++;
            }
        }
        if (bits % 2 == 1) {
            count += n / lcm_val;
        } else {
            count -= n / lcm_val;
        }
    }
    return count;
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> primes(k);
    for (int i = 0; i < k; ++i) {
        cin >> primes[i];
    }
    cout << count_divisible(n, primes) << endl;
    return 0;
}
