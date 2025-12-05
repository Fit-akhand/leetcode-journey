#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int count = 0;
        int sum2 = 0;

        for (int i = 0; i < n - 1; i++) {
            sum -= nums[i];
            sum2 += nums[i];

            int k = sum - sum2;
            if (k % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4}; // sample input
    Solution obj;
    cout << obj.countPartitions(nums) << endl;
    return 0;
}
