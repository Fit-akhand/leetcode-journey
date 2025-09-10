#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            // skip duplicates at the same recursion depth
            if (j != i && nums[j] == nums[i]) continue;

            swap(nums[i], nums[j]);
            solve(nums, i + 1, ans);
            swap(nums[i], nums[j]); // backtrack
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());  // sort to group duplicates
        solve(nums, 0, ans);
        return ans;
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = sol.permuteUnique(nums);

    for (auto &perm : result) {
        for (int x : perm) cout << x << " ";
        cout << endl;
    }
    return 0;
}
