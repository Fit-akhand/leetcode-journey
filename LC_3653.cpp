#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }

        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(4));
    cout << "Enter queries (l r k v):\n";
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
    }

    int result = obj.xorAfterQueries(nums, queries);

    cout << "Final XOR: " << result << endl;

    return 0;
}