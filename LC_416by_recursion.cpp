class Solution {
public:
    int getSum(const vector<int>& a) {
        int ans = 0;
        for (int x : a) ans += x;
        return ans;
    }

    bool solve(const vector<int>& nums, int index, int target) {
        if (target == 0) return true;                                  // found a subset
        if (index >= (int)nums.size() || target < 0) return false;     // out of range

        // include current element
        bool include = solve(nums, index + 1, target - nums[index]);
        // exclude current element
        bool exclude = solve(nums, index + 1, target);

        return include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int total = getSum(nums);
        if (total % 2 != 0) return false;              // odd sum → impossible
        int target = total / 2;
        return solve(nums, 0, target);
    }
};
