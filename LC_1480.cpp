#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            result.push_back(sum);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    
    vector<int> ans = s.runningSum(nums);

    cout << "Running Sum: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
