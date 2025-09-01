#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(const vector<int>& a) {
        int ans = 0;
        for (int x : a) ans += x;
        return ans;
    }

    // Memoization: dp[index][target] = -1 (unvisited), 0 (false), 1 (true)
    bool solve(const vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;                     
        if (index >= (int)nums.size() || target < 0) return false;    

        if (dp[index][target] != -1) return dp[index][target];

        // include current element
        bool include = solve(nums, index + 1, target - nums[index], dp);
        // exclude current element
        bool exclude = solve(nums, index + 1, target, dp);

        return dp[index][target] = (include || exclude);
    }

    bool canPartition(vector<int>& nums) {
        int total = getSum(nums);
        if (total % 2 != 0) return false;   
        int target = total / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(nums, 0, target, dp);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 5, 11, 5};  // Example
    if (sol.canPartition(nums))
        cout << "Can partition into equal subsets ✅" << endl;
    else
        cout << "Cannot partition ❌" << endl;

    return 0;
}
