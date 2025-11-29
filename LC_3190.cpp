#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 3 != 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 6, 7};

    Solution s;
    int result = s.minimumOperations(nums);

    cout << "Minimum operations: " << result << endl;

    return 0;
}
