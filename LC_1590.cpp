#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;

        long long rem = total % p;
        if (rem == 0) return 0;  // already divisible

        unordered_map<long long, int> mp;
        mp[0] = -1;  // prefix before start

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;

            long long need = (prefix - rem + p) % p;

            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }

            mp[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};

int main() {
    // Example test
    Solution s;
    vector<int> nums = {3, 1, 4, 2};
    int p = 6;
    cout << s.minSubarray(nums, p) << endl;
    return 0;
}
