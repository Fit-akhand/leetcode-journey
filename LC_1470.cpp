#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int size = nums.size();
        int odd = n;
        for(int i = 0; i < size - odd; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[n++]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;

    vector<int> result = sol.shuffle(nums, n);

    cout << "Shuffled Array: ";
    for(int x : result)
        cout << x << " ";
    cout << endl;
    
    return 0;
}
