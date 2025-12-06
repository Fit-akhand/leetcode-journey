#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        deque<int> minD, maxD;
        int l = 0;
        long long sum = dp[0];

        for (int r = 0; r < n; r++) {

            // maintain max deque
            while (!maxD.empty() && nums[maxD.back()] <= nums[r])
                maxD.pop_back();
            maxD.push_back(r);

            // maintain min deque
            while (!minD.empty() && nums[minD.back()] >= nums[r])
                minD.pop_back();
            minD.push_back(r);

            // shrink window until valid
            while (!maxD.empty() && !minD.empty() &&
                   nums[maxD.front()] - nums[minD.front()] > k) {
                
                sum = (sum - dp[l] + MOD) % MOD;
                l++;

                if (!minD.empty() && minD.front() < l) minD.pop_front();
                if (!maxD.empty() && maxD.front() < l) maxD.pop_front();
            }

            dp[r + 1] = sum;
            sum = (sum + dp[r + 1]) % MOD;
        }

        return dp[n] % MOD;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    cout << "Total partitions = " << sol.countPartitions(nums, k) << endl;

    return 0;
}
