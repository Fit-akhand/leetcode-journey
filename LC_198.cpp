#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 1. Recursion + Memoization (Top Down)
    int solveUsingMem(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        // Include
        int includeAns = nums[index] + solveUsingMem(nums, index + 2, dp);

        // Exclude
        int excludeAns = solveUsingMem(nums, index + 1, dp);

        dp[index] = max(includeAns, excludeAns);
        return dp[index];
    }

    // 2. Bottom-Up (Tabulation)
    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int includeAns = nums[i] + (i + 2 <= n ? dp[i + 2] : 0);
            int excludeAns = dp[i + 1];

            dp[i] = max(includeAns, excludeAns);
        }

        return dp[0];
    }

    // 3. Space Optimized
    int solveUsingSpaceOp(vector<int>& nums) {
        int n = nums.size();

        int next1 = 0; // dp[i+1]
        int next2 = 0; // dp[i+2]

        for (int i = n - 1; i >= 0; i--) {
            int includeAns = nums[i] + next2;
            int excludeAns = next1;

            int curr = max(includeAns, excludeAns);

            // Update pointers
            next2 = next1;
            next1 = curr;
        }

        return next1;
    }

    int rob(vector<int>& nums) {
        // Uncomment any method you want to use

        // int n = nums.size();
        // vector<int> dp(n, -1);
        // return solveUsingMem(nums, 0, dp);

        // return solveUsingTabulation(nums);

        return solveUsingSpaceOp(nums);
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Maximum money robbed: " << obj.rob(nums) << endl;
    return 0;
}