#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <sstream>

using namespace std;
long long MAXN=1e14;

// Function to evaluate the expression string respecting operator precedence
long long evaluateExpression(const string& expr) {
    vector<long long> terms;
    stringstream termStream(expr);
    string term;
    
    // Split by '+'
    while (getline(termStream, term, '+')) {
        vector<long long> factors;
        stringstream factorStream(term);
        string factor;
        
        // Split by '*'
        while (getline(factorStream, factor, '*')) {
            factors.push_back(stoll(factor));
        }
        
        long long product = 1;
        for (long long f : factors) {
            product *= f;
            if(product >MAXN || product<0)return MAXN;
        }
        
        terms.push_back(product);
    }
    
    long long result = 0;
    for (long long t : terms) {
        result += t;
    }
    
    return result;
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        if (n == 2) {
            cout << s << endl;
            continue;
        }
        
        vector<char> operators = {'+', '*'};
        long long min_value = LLONG_MAX;
        
        int numOperators = n - 2;
        int totalCombinations = 1 << numOperators; // 2^(n-2) combinations
        
        for (int comb = 0; comb < totalCombinations; ++comb) {
            string expr;
            expr += s[0];
            
            for (int i = 0; i < numOperators; ++i) {
                expr += (comb & (1 << i)) ? '*' : '+';
                expr += s[i + 1];
            }
            expr += s[n - 1];
            
            long long value = evaluateExpression(expr);
            min_value = min(min_value, value);
        }
        
        cout << min_value << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
