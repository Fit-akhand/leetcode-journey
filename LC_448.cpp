#include <iostream>
#include <vector>
#include <cmath> // for abs()
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark seen numbers as negative
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        // Collect indices where numbers are still positive
        vector<int> missing;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                missing.push_back(i + 1);
            }
        }

        return missing;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> result = sol.findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
