#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mod = 1000000007;

    // Space Optimized DP
    int numRollsToTarget(int n, int k, int target) {
        vector<long long> prev(target + 1, 0);
        vector<long long> curr(target + 1, 0);

        prev[0] = 1;

        for (int a = 1; a <= n; a++) {
            fill(curr.begin(), curr.end(), 0); // reset

            for (int t = 1; t <= target; t++) {
                long long ans = 0;

                for (int val = 1; val <= k && val <= t; val++) {
                    ans = (ans + prev[t - val]) % mod;
                }

                curr[t] = ans;
            }

            prev = curr;
        }

        return prev[target];
    }
};

int main() {
    Solution obj;

    int n, k, target;

    cout << "Enter number of dice (n): ";
    cin >> n;

    cout << "Enter number of faces (k): ";
    cin >> k;

    cout << "Enter target sum: ";
    cin >> target;

    int result = obj.numRollsToTarget(n, k, target);

    cout << "Number of ways: " << result << endl;

    return 0;
}