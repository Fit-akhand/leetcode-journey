#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔴 1. Pure Recursion (Exponential)
    int SolveUsingRecursion(vector<int>& nums, int prev, int curr){
        if(curr >= nums.size()){
            return 0;
        }

        int include = 0;
        if(prev == -1 || nums[prev] < nums[curr]){
            include = 1 + SolveUsingRecursion(nums, curr, curr+1);
        }

        int exclude = SolveUsingRecursion(nums, prev, curr+1);

        return max(include, exclude);
    }


    // 🟡 2. Memoization (Top-Down DP)
    int SolveUsingDp(vector<int>& nums, int prev, int curr, vector<vector<int>>& dp){
        if(curr >= nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int include = 0;
        if(prev == -1 || nums[prev] < nums[curr]){
            include = 1 + SolveUsingDp(nums, curr, curr+1, dp);
        }

        int exclude = SolveUsingDp(nums, prev, curr+1, dp);

        return dp[curr][prev+1] = max(include, exclude);
    }


    // 🟢 3. Tabulation (Bottom-Up DP)
    int SolveUsingTabulation(vector<int>& nums){
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr = n-1; curr >= 0; curr--){
            for(int prev = curr-1; prev >= -1; prev--){

                int include = 0;
                if(prev == -1 || nums[prev] < nums[curr]){
                    include = 1 + dp[curr+1][curr+1];
                }

                int exclude = dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }


    int lengthOfLIS(vector<int>& nums) {

        // 🔴 Recursion
        // return SolveUsingRecursion(nums, -1, 0);

        // 🟡 Memoization
        // int n = nums.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return SolveUsingDp(nums, -1, 0, dp);

        // 🟢 Tabulation
        return SolveUsingTabulation(nums);
    }
};


int main() {
    Solution obj;

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Length of LIS: " << obj.lengthOfLIS(nums) << endl;

    return 0;
}