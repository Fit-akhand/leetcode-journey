#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            int count = 0;

            for(int j = 0; j < nums.size(); j++){
                if(nums[i] > nums[j]){
                    count++;
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {8, 1, 2, 2, 3};
    vector<int> result = s.smallerNumbersThanCurrent(nums);

    for(int x : result) cout << x << " ";  
    // Expected output: 4 0 1 1 3
    cout << endl;

    return 0;
}
