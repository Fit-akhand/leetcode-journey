#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double temp = 0;

        // Sum of the first k elements
        for (int j = 0; j < k; j++) {
            temp += nums[j];
        }

        double ans = temp;

        // Sliding window
        for (int i = k; i < nums.size(); i++) {
            temp = temp + nums[i] - nums[i - k];
            ans = max(ans, temp);
        }

        return ans / k;
    }
};
