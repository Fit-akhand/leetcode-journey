#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);  // Sentinel to prevent out-of-bounds
        long long sum = 0;
        long long curr = 1;

        for (int i = 0; i < nums.size() && k > 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates

            if (curr < nums[i]) {
                long long gap = min<long long>(nums[i] - curr, k);
                sum += (curr + (curr + gap - 1)) * gap / 2; // Arithmetic sum
                k -= gap;
            }
            curr = max(curr, (long long)nums[i] + 1);
        }
        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 4, 25, 10, 25};
    int k = 2;

    cout << "Input nums: [1, 4, 25, 10, 25]" << endl;
    cout << "k = 2" << endl;

    long long result = sol.minimalKSum(nums, k);
    cout << "Minimal K Sum = " << result << endl;

    return 0;
}
