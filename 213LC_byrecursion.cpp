#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robber(vector<int>& nums, int index, int end) {
        if (index > end) {
            return 0;
        }
        // include
        int include_ans = nums[index] + robber(nums, index + 2, end);
        // exclude
        int exclude_ans = robber(nums, index + 1, end);

        return max(include_ans, exclude_ans);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // edge case: only one house

        // Case 1: Rob houses from 0 to n-2
        int option1 = robber(nums, 0, n - 2);

        // Case 2: Rob houses from 1 to n-1
        int option2 = robber(nums, 1, n - 1);

        return max(option1, option2);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2};  // Example input
    cout << "Max money robbed: " << sol.rob(nums) << endl;

    return 0;
}
