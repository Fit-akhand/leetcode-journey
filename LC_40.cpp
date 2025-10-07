#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) continue; // skip duplicates
            if (candidates[j] > target) break; // pruning

            temp.push_back(candidates[j]);
            solve(candidates, target - candidates[j], j + 1, temp, ans); // move forward (j+1)
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, temp, ans);
        return ans;
    }
};

// 🔹 Local testing
int main() {
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    cout << "Combinations:\n";
    for (auto &comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
