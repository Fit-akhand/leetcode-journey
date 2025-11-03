#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        // Process first window of size k
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        // Process remaining windows
        for (int i = k; i < nums.size(); i++) {
            // Remove elements that are out of this window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Maintain elements in decreasing order
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Current window max is at front
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution s;
    vector<int> result = s.maxSlidingWindow(nums, k);

    cout << "Output: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
