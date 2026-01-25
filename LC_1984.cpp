#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;

        for (int i = 0; i + k - 1 < n; i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {9, 4, 1, 7};
    int k = 2;

    Solution sol;
    cout << "Minimum Difference: " << sol.minimumDifference(nums, k) << endl;

    return 0;
}
