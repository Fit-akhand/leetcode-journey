#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int> &nums, int target, vector<int> &ans, int index, int e) {
        if (index >= nums.size()) return;

        if (nums[index] == target && e == 0) {
            ans[0] = index; // first occurrence
            e = 1;
        }
        if (nums[index] == target) {
            ans[1] = index; // last occurrence
        }

        solve(nums, target, ans, index + 1, e);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        solve(nums, target, ans, 0, 0);
        return ans;
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    Solution sol;
    vector<int> res = sol.searchRange(nums, target);

    cout << res[0] << " " << res[1] << endl;

    return 0;
}
