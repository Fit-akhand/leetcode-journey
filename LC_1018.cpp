#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int sum = 0;

        for(int bit : nums) {
            sum = (sum * 2 + bit) % 5;
            ans.push_back(sum == 0);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of bits: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter bits (0 or 1 only): ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<bool> result = obj.prefixesDivBy5(nums);

    cout << "Result: ";
    for(bool val : result) {
        cout << (val ? "true " : "false ");
    }
    cout << endl;

    return 0;
}
