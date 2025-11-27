#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        freq[0] = 1;  // prefix sum == 0 initially

        long long prefix = 0;
        int count = 0;

        for (int x : nums) {
            prefix += x;

            // Safe modulo (handles negative prefix sums)
            int mod = ((prefix % k) + k) % k;

            count += freq[mod];
            freq[mod]++;
        }

        return count;
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
    cout << s.subarraysDivByK(nums, k);

    return 0;
}
