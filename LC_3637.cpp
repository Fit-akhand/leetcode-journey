#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 1;

        // Phase 1: strictly increasing
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }
        if (i == 1 || i == n) return false;

        // Phase 2: strictly decreasing
        while (i < n && nums[i] < nums[i - 1]) {
            i++;
        }
        if (i == n) return false;

        // Phase 3: strictly increasing
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
        }

        return i == n;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 3, 5, 4, 2, 6},    // true
        {1, 2, 3, 4, 5},       // false
        {1, 4, 3, 2, 1},       // false
        {1, 3, 2, 4},          // true
        {1, 2, 2, 1, 3},       // false (not strictly)
    };

    for (auto& nums : testCases) {
        cout << "[ ";
        for (int x : nums) cout << x << " ";
        cout << "] -> ";

        cout << (sol.isTrionic(nums) ? "true" : "false") << endl;
    }

    return 0;
}
