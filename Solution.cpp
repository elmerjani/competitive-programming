#include <bits/stdc++.h>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int total_candidates = n + m + 1;
        vector<int> a(total_candidates);
        vector<int> b(total_candidates);

        for (int i = 0; i < total_candidates; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < total_candidates; ++i) {
            cin >> b[i];
        }

        // Prefix sums for programming and testing skills
        vector<long long> prefix_prog(total_candidates + 1, 0);
        vector<long long> prefix_test(total_candidates + 1, 0);

        for (int i = 1; i <= total_candidates; ++i) {
            prefix_prog[i] = prefix_prog[i - 1] + a[i - 1];
            prefix_test[i] = prefix_test[i - 1] + b[i - 1];
        }

        // Suffix sums for programming and testing skills
        vector<long long> suffix_prog(total_candidates + 1, 0);
        vector<long long> suffix_test(total_candidates + 1, 0);

        for (int i = total_candidates - 1; i >= 0; --i) {
            suffix_prog[i] = suffix_prog[i + 1] + a[i];
            suffix_test[i] = suffix_test[i + 1] + b[i];
        }

        // Results for each candidate
        vector<long long> results(total_candidates);

        for (int i = 0; i < total_candidates; ++i) {
            // Total skill without candidate i
            long long skill_without_i = 0;

            // Calculate the skill of the team excluding candidate i
            // Assume candidate i is excluded, calculate using prefix and suffix sums
            long long total_prog = prefix_prog[i] + suffix_prog[i + 1];
            long long total_test = prefix_test[i] + suffix_test[i + 1];

            // Calculate the number of programmers and testers in the remaining candidates
            int remaining_prog = n;
            int remaining_test = m;

            // Determine initial assignment of remaining candidates
            vector<int> roles(total_candidates, -1); // -1: unassigned, 0: programmer, 1: tester
            for (int j = 0; j < total_candidates; ++j) {
                if (j == i) continue; // Skip the excluded candidate

                if (a[j] >= b[j]) {
                    if (remaining_prog > 0) {
                        roles[j] = 0; // Programmer
                        remaining_prog--;
                    } else {
                        roles[j] = 1; // Tester
                        remaining_test--;
                    }
                } else {
                    if (remaining_test > 0) {
                        roles[j] = 1; // Tester
                        remaining_test--;
                    } else {
                        roles[j] = 0; // Programmer
                        remaining_prog--;
                    }
                }
            }

            // Calculate the total skill for the remaining candidates
            for (int j = 0; j < total_candidates; ++j) {
                if (j == i) continue;
                if (roles[j] == 0) {
                    skill_without_i += a[j];
                } else {
                    skill_without_i += b[j];
                }
            }

            results[i] = skill_without_i;
        }

        // Print results for the current test case
        for (int i = 0; i < total_candidates; ++i) {
            cout << results[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
