#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == original) {
                original *= 2;
                i = -1; // restart loop
            }
        }
        return original;
    }
};

int main() {
    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;

    Solution s;
    int result = s.findFinalValue(nums, original);

    cout << "Final Value: " << result << endl;
    return 0;
}
