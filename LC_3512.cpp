#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;

        if (sum % k == 0) return 0;
        return sum % k;
    }
};

int main() {
    vector<int> nums = {3, 1, 4};
    int k = 5;

    Solution s;
    cout << s.minOperations(nums, k) << endl;

    return 0;
}
