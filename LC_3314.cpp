#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            // Special case: impossible
            if (n == 2) {
                ans.push_back(-1);
                continue;
            }

            int t = 0;
            // Count trailing ones in n
            while (n & (1 << t)) {
                t++;
            }

            // Remove the highest bit in the trailing-ones block
            ans.push_back(n - (1 << (t - 1)));
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 3, 5, 7};
    vector<int> nums2 = {11, 13, 31};

    vector<int> res1 = sol.minBitwiseArray(nums1);
    vector<int> res2 = sol.minBitwiseArray(nums2);

    for (int x : res1) cout << x << " ";
    cout << endl;

    for (int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}
