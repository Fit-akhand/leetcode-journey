#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int ans = INT_MAX;
        int sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};

int main() {
    Solution obj;

    int target;
    cout << "Enter target: ";
    cin >> target;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = obj.minSubArrayLen(target, nums);
    cout << "Minimum subarray length: " << result << endl;

    return 0;
}
