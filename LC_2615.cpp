#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp;

        // Step 1: Group all indices for each number
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        // Step 2: For each unique number, calculate distances using prefix sums
        for (auto &it : mp) {
            vector<int> &idx = it.second;
            int m = idx.size();

            // Build prefix sum array of indices
            vector<long long> prefix(m + 1, 0);
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + idx[i];
            }

            // Compute distances for each index
            for (int i = 0; i < m; i++) {
                long long left  = (long long)idx[i] * i - prefix[i];
                long long right = (prefix[m] - prefix[i + 1]) - (long long)idx[i] * (m - i - 1);
                ans[idx[i]] = left + right;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1, 1, 2};

    cout << "Input: [ ";
    for (int num : nums) cout << num << " ";
    cout << "]" << endl;

    vector<long long> result = sol.distance(nums);

    cout << "Output: [ ";
    for (long long val : result) cout << val << " ";
    cout << "]" << endl;

    return 0;
}
