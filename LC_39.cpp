#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(vector<int>& arr, int target, int i, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (i >= arr.size() || target < 0) {
            return;
        }

        // include current element (i can be reused)
        temp.push_back(arr[i]);
        solve(arr, target - arr[i], i, temp, ans); 
        temp.pop_back();

        // exclude current element (move forward)
        solve(arr, target, i + 1, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, temp, ans);
        return ans;
    }
};

// 🔹 For local testing
int main() {
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations are:\n";
    for (auto &comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
