#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            // If num is even, it's impossible
            if ((num & 1) == 0) {
                ans.push_back(-1);
                continue;
            }

            // Count trailing 1s in binary representation
            int k = 0;
            int temp = num;
            while (temp & 1) {
                k++;
                temp >>= 1;
            }

            // Compute minimum valid x
            int x = num - (1 << (k - 1));
            ans.push_back(x);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 5, 7, 2};
    vector<int> result = sol.minBitwiseArray(nums);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
    