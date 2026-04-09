#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive
    int SolveUsingRec(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;

        int ans = (SolveUsingRec(n - 2, k) + SolveUsingRec(n - 1, k)) * (k - 1);
        return ans;
    }

    // Memoization
    int SolveUsingMem(int n, int k, vector<int>& dp) {
        if (n == 1) return k;
        if (n == 2) return k * k;

        if (dp[n] != -1) return dp[n];

        int ans = (SolveUsingMem(n - 2, k, dp) + SolveUsingMem(n - 1, k, dp)) * (k - 1);
        dp[n] = ans;
        return ans;
    }

    // Tabulation
    int SolveUsingTabulation(int n, int k) {
        vector<int> dp(n + 1, -1);

        dp[1] = k;
        dp[2] = k * k;

        for (int a = 3; a <= n; a++) {
            dp[a] = (dp[a - 2] + dp[a - 1]) * (k - 1);
        }

        return dp[n];
    }

    // Space Optimized
    int solveToSpaceOptimize(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;

        int prev = k;       // dp[1]
        int curr = k * k;   // dp[2]

        for (int a = 3; a <= n; a++) {
            int ans = (curr + prev) * (k - 1);
            prev = curr;
            curr = ans;
        }

        return curr;
    }

    int countWays(int n, int k) {
        return solveToSpaceOptimize(n, k);
    }
};

int main() {
    Solution obj;

    int n, k;

    cout << "Enter number of posts (n): ";
    cin >> n;

    cout << "Enter number of colors (k): ";
    cin >> k;

    int result = obj.countWays(n, k);

    cout << "Number of ways to paint fence: " << result << endl;

    return 0;
}