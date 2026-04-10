#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            string temp = "";

            for (int j = i; j < n; j++) {
                if (nums[j] % p == 0) cnt++;

                if (cnt > k) break;

                temp += to_string(nums[j]) + "#";
                st.insert(temp);
            }
        }

        return st.size();
    }
};

int main() {
    int n, k, p;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k and p: ";
    cin >> k >> p;

    Solution sol;
    int result = sol.countDistinct(nums, k, p);

    cout << "Number of distinct valid subarrays: " << result << endl;

    return 0;
}