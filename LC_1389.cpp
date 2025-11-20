#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            ans.insert(ans.begin() + index[i], nums[i]);
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<int> nums = {0,1,2,3,4};
    vector<int> index = {0,1,2,2,1};

    vector<int> ans = s.createTargetArray(nums, index);

    for(int x : ans)
        cout << x << " ";

    return 0;
}
