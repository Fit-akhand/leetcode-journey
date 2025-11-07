#include <bits/stdc++.h>    // includes all standard libraries
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int k = nums[i];
            ans.push_back(nums[k]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    
    // Function call
    vector<int> result = sol.buildArray(nums);
    
    // Output result
    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
