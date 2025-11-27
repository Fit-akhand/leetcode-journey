#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> minPref(k, LLONG_MAX);
        long long ans = LLONG_MIN;

        for (int i = 0; i <= n; i++) {
            int mod = i % k;

            if (minPref[mod] != LLONG_MAX) {
                ans = max(ans, prefix[i] - minPref[mod]);
            }

            minPref[mod] = min(minPref[mod], prefix[i]);
        }

        return ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution s;
    cout << s.maxSubarraySum(nums, k);

    return 0;
}
