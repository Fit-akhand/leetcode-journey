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
        if (j > i && candidates[j] == candidates[j - 1]) continue; // ✅ skip duplicates
        if (candidates[j] > target) break; // ✅ pruning since sorted

        temp.push_back(candidates[j]);
        solve(candidates, target - candidates[j], j + 1, temp, ans); // move forward (j+1)
        temp.pop_back();
    }
}


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates,target,0,temp,ans);

        return ans;

    }
};