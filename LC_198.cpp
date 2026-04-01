#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int SolveUsingMem(vector<int> nums, int index, vector<int>& dp) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int include_ans = nums[index] + SolveUsingMem(nums, index + 2, dp);
        int exclude_ans = SolveUsingMem(nums, index + 1, dp);

        return dp[index] = max(include_ans, exclude_ans);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return SolveUsingMem(nums, 0, dp);
    }
};

int main() {
    Solution obj;
    vector<int> nums = {2, 7, 9, 3, 1};

    int result = obj.rob(nums);
    cout << "Max money: " << result << endl;

    return 0;
}