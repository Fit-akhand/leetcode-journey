#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> seen;

        for (int i = 0; i < nums.size() - 1; i++) {
            int s = nums[i] + nums[i + 1];
            if (seen.count(s))
                return true;
            seen.insert(s);
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solution sol;
    cout << (sol.findSubarrays(nums) ? "true" : "false") << endl;

    return 0;
}
