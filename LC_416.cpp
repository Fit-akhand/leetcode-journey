#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool solveUsingMem(vector<int>& nums, int index, int target, vector<vector<int>>& dp){

        if(target == 0) return true;
        if(index >= nums.size() || target < 0) return false;

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool include = solveUsingMem(nums, index+1, target-nums[index], dp);
        bool exclude = solveUsingMem(nums, index+1, target, dp);

        return dp[index][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }

        if(sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return solveUsingMem(nums, 0, target, dp);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 5, 11, 5};

    if(obj.canPartition(nums)) {
        cout << "Can be partitioned into equal subset sum" << endl;
    } else {
        cout << "Cannot be partitioned" << endl;
    }

    return 0;
}