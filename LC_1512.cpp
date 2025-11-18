#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {1, 2, 3, 1, 1, 3}; // sample input
    int result = sol.numIdenticalPairs(nums);
    
    cout << "Number of good pairs: " << result << endl;
    return 0;
}
